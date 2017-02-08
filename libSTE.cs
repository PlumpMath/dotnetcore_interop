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

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_state(IntPtr ste,  [MarshalAs(UnmanagedType.LPStr)] string locationCode, bool residentStateFlag, bool exemptFlag, int roundingOption, double additionalWH, double ytd, double mostRecentWH, bool hasNonResCertificate );
        
        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_state_misc(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string  locationCode, [MarshalAs(UnmanagedType.LPStr)] string  parmName, [MarshalAs(UnmanagedType.LPStr)] string  parmValue );

        [DllImport(LIBSTE, CharSet = CharSet.Ansi)]
        private static extern unsafe IntPtr ste_set_county(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string locationCode, bool isExempt, bool isResident );

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_medicare(IntPtr ste);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_quit(IntPtr ste);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_eic(IntPtr ste);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_state(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string locationCode, [Out, MarshalAs(UnmanagedType.R8)] out double sitCTD, [Out, MarshalAs(UnmanagedType.R8)] out double supplementalCTD);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_county(IntPtr ste, [MarshalAs(UnmanagedType.LPStr)] string locationCode,  [Out, MarshalAs(UnmanagedType.R8)] out double countyCTD, [Out, MarshalAs(UnmanagedType.R8)] out double countySupplementalCTD);

        [DllImport(LIBSTE)]
        private static extern unsafe double ste_get_federal(IntPtr ste, [Out, MarshalAs(UnmanagedType.R8)] out double fitCTD,  [Out, MarshalAs(UnmanagedType.R8)] out double  supplementalCTD);

        public void  Demo()
        {
            init();
        }

        internal static unsafe void init()
        {

            const string FED_LOCATION_CODE = "00-000-00000";
            
            var ste = ste_init("/home/leo/ste/ste-root/");
            
            if(ste == IntPtr.Zero){
                Console.WriteLine("Unable to start STE");
                return;
            }

            var handle = (ste_handle) Marshal.PtrToStructure(ste, typeof(ste_handle));

            Console.WriteLine("STE Initialized");

            ste_set_payroll_run_parameters(ste, "2013-01-01", 52, 1);

            ste_clear_calculations(ste);

            ste_set_calcmethod(ste, FED_LOCATION_CODE, (int)ste_CALC_Method.ste_CALC_Method_Annualized,(int)ste_CALC_Method.ste_CALC_Method_None);
            
            ste_set_wages(ste, FED_LOCATION_CODE, (int)ste_WAGE_Type.ste_WAGE_Regular, 40, 5000, 0, 0, 0);

            ste_set_federal(ste, false, (int)Filing.ste_FED_Married, 5, true, 0, 0, 0);

            ste_set_fica(ste, false, false, 100, 200, false);

            ste_set_medicare(ste, false, 0);

            ste_set_eic(ste, (int)EIC.ste_EIC_None, 0, false);

            //The location code for Indianapolis, Indiana (Marion County)
            //is "18-097-452890"
            //The state GNIS code is 18
            //The county GNIS code is 097
            //The city GNIS code is 452890

            ste_set_state(ste, "18-097-452890", true, false, (int)Rounding.ste_STATE_DefaultRounding, 0, 0, 0,false);

            ste_set_calcmethod(ste, "18-097-452890", (int)ste_CALC_Method.ste_CALC_Method_Annualized, (int)ste_CALC_Method.ste_CALC_Method_None);

            ste_set_wages(ste, "18-097-452890", (int)ste_WAGE_Type.ste_WAGE_Regular, 40, 5000, 0, 0, 0);

            // The miscellaneous parameters vary by state
            // Indiana requires the following two parameters to withhold state tax

            ste_set_state_misc(ste, "18-097-452890", "PERSONALEXEMPTIONS", "1");

            ste_set_state_misc(ste, "18-097-452890", "DEPENDENTEXEMPTIONS", "2");

            ste_set_county(ste, "18-097-452890", false, true);

            ste_calculate(ste);

            Console.WriteLine("STE Version: {0}", version(ste));

            Console.WriteLine("STE Version: {0}", version2(ste));

            Console.WriteLine("STE License: {0}", license(ste));

            Console.WriteLine("FICA Withholding: {0}", ste_get_fica(ste));

            Console.WriteLine("Medicare Withholding: {0}", ste_get_medicare(ste));

            Console.WriteLine("Federal Withholding: {0}", get_federal(ste));

            Console.WriteLine("Earned Inc. Credit: {0}", ste_get_eic(ste));

            Console.WriteLine("State Withholding: {0}", get_state(ste, "18-097-452890"));

            Console.WriteLine("County Withholding: {0}", get_county(ste, "18-097-452890"));

            Console.WriteLine("");
            
            ste_quit(ste);
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

        internal static unsafe double get_state(IntPtr handle, string locationCode)
        {
            double sitCTD = 0, sitSupplementalCTD = 0, result = 0;

            result = ste_get_state(handle, locationCode,out sitCTD, out sitSupplementalCTD);
            
            return result;
        }

        internal static unsafe double get_county(IntPtr handle, string locationCode)
        {
            double countyCTD = 0, countySupplementalCTD = 0, result = 0;

            result = ste_get_county(handle, locationCode,out countyCTD, out countySupplementalCTD);
            
            return result;
        }
        
        /// <summary>
        /// /// This version is more verbose but the Marshaling of types is better. Marshal.PtrToStringUTF8 ignores bytes 0
        /// </summary>
        /// <param name="handle"></param>
        internal static  unsafe string version(IntPtr handle)
        {

            string result = String.Empty;
            
           fixed(byte* bufferPtr = new Byte[100])
            {

               ste_version(handle, bufferPtr);

              var resultPtr = new IntPtr(bufferPtr);
              result = Marshal.PtrToStringUTF8(resultPtr);
            }

            return result;
        }


        /// <summary>
        /// This version of code, uses a different calling scheme, it is less verbose, but the issue comes from needing a out 
        /// variable with the exact byte size, otherwise we get a lot of zeroes in the GetString method which translate to ? chars  
        /// or we can trim the empty chars of the result string and keep the big array
        /// </summary>
        /// <param name="handle"></param>
        internal static  unsafe string version2(IntPtr handle)
        {
            var version = new byte[100];

            ste_version2(handle,  version);
            var result = System.Text.Encoding.UTF8.GetString(version).Trim(new char[] { '\0' });;

            return result;
        }
        
        internal static  unsafe string license(IntPtr handle)
        {

            string result = String.Empty;
            
            fixed(byte* bufferPtr = new Byte[100])
            {

                ste_license_info(handle, bufferPtr);

                var resultPtr = new IntPtr(bufferPtr);
                result = Marshal.PtrToStringUTF8(resultPtr);
            }

            return result;
        }


        [StructLayout(LayoutKind.Sequential)]
        public struct ste_handle {
        }   

        enum Rounding
        {
            ste_STATE_NoRounding = 0,
            ste_STATE_YesRounding= 1,
            ste_STATE_DefaultRounding= 2
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