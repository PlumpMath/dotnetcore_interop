using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace ConsoleApplication
{
    /// corefx System Interop for System.Console
    /// https://github.com/dotnet/corefx/blob/79d44f202e4b6d000ca6c6885a24549a55db38f1/src/System.Console/src/Interop/Interop.manual.Unix.cs
    ///
    public class InteropTests
    {
         const string LIBC = "libc";

        [DllImport(LIBC, EntryPoint = "getenv")]
        private static extern IntPtr getenv_core(string name);

        internal static string getenv(string name)
        {
            return Marshal.PtrToStringAnsi(getenv_core(name));
        }

        [DllImport(LIBC)]
        internal static extern unsafe int snprintf(byte* str, IntPtr size, string format, string arg1);

        [DllImport(LIBC)]
        internal static extern unsafe int snprintf(byte* str, IntPtr size, string format, int arg1);
    
        public void TestString()
        {
            var result = getenv("HOME");

            Console.WriteLine(result);   
            readFromPointer();
        }

        internal static unsafe void readFromPointer()
        {
            byte[] buffer = new Byte[10];
            string result = String.Empty;
            
            fixed(byte* bufferPtr = buffer){

                snprintf(bufferPtr, new IntPtr(buffer.Length), "test %s", "Leo");

                var ptr = new IntPtr(bufferPtr);
                result = Marshal.PtrToStringAnsi(ptr);
               
            }
            Console.WriteLine(result);
            
        }

        private static byte[] StrToByteArray(string str)
        {
            System.Text.UTF8Encoding encoding = new System.Text.UTF8Encoding();
            return encoding.GetBytes(str);
        }
    }
}