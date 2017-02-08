using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace ConsoleApplication
{
    /// corefx System Interop for System.Console
    /// https://github.com/dotnet/corefx/blob/79d44f202e4b6d000ca6c6885a24549a55db38f1/src/System.Console/src/Interop/Interop.manual.Unix.cs
    ///
    public class libSTE
    {
        const string LIBSTE = "libste";

        [DllImport(LIBSTE)]
        private static extern unsafe IntPtr ste_init([MarshalAs(UnmanagedType.LPStr)] string dirLocation);

        [DllImport(LIBSTE, EntryPoint="ste_version", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_version2(IntPtr ste,  [Out, MarshalAs(UnmanagedType.LPArray)] byte[] version);

        [DllImport(LIBSTE, CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_version(IntPtr ste, byte* version);

        [DllImport(LIBSTE)]
        private static extern unsafe IntPtr ste_license_info(IntPtr ste, byte* license);

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_payroll_run_parameters(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string paydate, int payPeriodsPerYear, int payPeriodNumber);

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_clear_calculations(IntPtr ste);

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_calcmethod(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string  locationCode, int methodRegularWages, int methodSupplementalWages );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_wages(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string locationCode, int wageType, double hours, double ctd, double mtd, double qtd, double ytd );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_federal(IntPtr ste, bool exemptStatus, int filingStatus, int numAllowances, bool roundOption, double additionalWH, double ytd, double mostRecentWH );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_medicare(IntPtr ste, bool exemptStatus, double ytd );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_eic(IntPtr ste, int filingStatus, double ytd, bool filingJointly );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_fica(IntPtr ste, bool exemptStatusEE, bool exemptStatusER, double ytdEE, double ytdER, bool autoAdjust );

        [DllImport(LIBSTE)]
        private static extern unsafe IntPtr ste_calculate(IntPtr ste);
        
         [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_fica(IntPtr ste);

         [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_medicare(IntPtr ste);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_federal(IntPtr ste, [Out, MarshalAs(UnmanagedType.R8)] out double fitCTD,  [Out, MarshalAs(UnmanagedType.R8)] out double  supplementalCTD);

        internal static unsafe void SetPayrollParameters(IntPtr ste)
        {

            var result = ste_set_payroll_run_parameters(ste, "2013-01-01", 52, 1);

        }

        public void  TestString()
        {
            init();
        }

        internal static unsafe void init(){
            
            var result = ste_init("/home/leo/ste/ste-root/");
            
            if(result == IntPtr.Zero){
                Console.WriteLine("Unable to start STE");
                return;
            }

            var handle = (ste_handle) Marshal.PtrToStructure(result, typeof(ste_handle));

            Console.WriteLine("STE Initialized");

            version(result);
            version2(result);

            license(result);
            
            SetPayrollParameters(result);

            ste_clear_calculations(result);

            ste_set_calcmethod(result, "00-000-00000", (int)ste_CALC_Method.ste_CALC_Method_Annualized,(int)ste_CALC_Method.ste_CALC_Method_None);
            
            ste_set_wages(result, "00-000-00000", (int)ste_WAGE_Type.ste_WAGE_Regular, 40, 5000, 0, 0, 0);

            ste_set_federal(result, false, (int)Filing.ste_FED_Married, 5, true, 0, 0, 0);

            ste_set_fica(result, false, false, 100, 200, false);

            ste_set_medicare(result, false, 0);

            ste_set_eic(result, (int)EIC.ste_EIC_None, 0, false);

            ste_calculate(result);

            Console.WriteLine("FICA Withholding: {0}", ste_get_fica(result));

            Console.WriteLine("Medicare Withholding: {0}", ste_get_medicare(result));

            Console.WriteLine("Federal Withholding: {0}", get_federal(result));

            Console.WriteLine("");
        }

        /// <summary>
        ///  This method gets the federal withholdings,
        /// the signature supports the result value from a pointer, to do this we have to make the parameter to be
        /// MarshalAs(UnmanagedType.R8) (R8 is double), Out, because its an out param, and the out C# modifier to properly get the result values.
        /// For the following .h signature:
        /// <code>
        ///     ste_get_federal(const ste_handle *ste, double *fitCTD, double *supplementalCTD);
        /// </code>
        /// The DllImport should be:
        ///  <code>
        ///     ste_get_federal(IntPtr ste, [Out, MarshalAs(UnmanagedType.R8)] out double fitCTD,  [Out, MarshalAs(UnmanagedType.R8)] out double  supplementalCTD);
        /// </code>
        /// </summary>
        /// <param name="handle"></param>
        /// <returns></returns>
        internal static unsafe double get_federal(IntPtr handle)
        {
            double fitCTD = 0, supplementalCTD = 0, result = 0;

            result = ste_get_federal(handle, out fitCTD, out supplementalCTD);
            
            return result;
        }
        
        /// <summary>
        /// /// This version is more verbose but the Marshaling of types is better. Marshal.PtrToStringUTF8 ignores bytes 0
        /// </summary>
        /// <param name="handle"></param>
        internal static  unsafe void version(IntPtr handle)
        {

            string result = String.Empty;
            
           fixed(byte* bufferPtr = new Byte[100])
            {

               ste_version(handle, bufferPtr);

              var resultPtr = new IntPtr(bufferPtr);
              result = Marshal.PtrToStringUTF8(resultPtr);
            }

            Console.WriteLine("Version: " + result);
        }


        /// <summary>
        /// This version of code, uses a different calling scheme, it is less verbose, but the issue comes from needing a out 
        /// variable with the exact byte size, otherwise we get a lot of zeroes in the GetString method which translate to ? chars  
        /// or we can trim the empty chars of the result string and keep the big array
        /// </summary>
        /// <param name="handle"></param>
        internal static  unsafe void version2(IntPtr handle)
        {
            var version = new byte[100];

            ste_version2(handle,  version);
            var result = System.Text.Encoding.UTF8.GetString(version).Trim(new char[] { '\0' });;

            Console.WriteLine("Version: " + result);
        }
        
        internal static  unsafe void license(IntPtr handle)
        {

            string result = String.Empty;
            
            fixed(byte* bufferPtr = new Byte[100])
            {

                ste_license_info(handle, bufferPtr);

                var resultPtr = new IntPtr(bufferPtr);
                result = Marshal.PtrToStringUTF8(resultPtr);
            }

            Console.WriteLine("License: " + result);
        }


        [StructLayout(LayoutKind.Sequential)]
        public struct ste_handle {
        }   

        enum EIC
        {
            ste_EIC_None = 0,
            ste_EIC_Single=1,
            ste_EIC_Married_One_Certificate	= 2,
            ste_EIC_Married_Two_Certificates = 3
        }

        enum Filing{
            ste_FED_Single	= 1,
            ste_FED_Married =2,
            ste_FED_Married_Use_Single_Rate	= 3,
            ste_FED_NonresidentAlien =4
        }
        enum ste_WAGE_Type{
            ste_WAGE_Regular = 1
        }

        enum ste_CALC_Method{
            ste_CALC_Method_Annualized=1,
            ste_CALC_Method_Cumulative=2,
            ste_CALC_Method_Flat=3,
            ste_CALC_Method_CurrentAggregation=4,
            ste_CALC_Method_PreviousAggregation=5,
            ste_CALC_Method_Daily=6,
            ste_CALC_Method_None=7

        }

    }
}