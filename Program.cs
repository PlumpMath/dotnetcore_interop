using System;

namespace ConsoleApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Printing from an Interop");
            
            var interop = new libSTE();
            interop.TestString();


        //    var t = new InteropTests();
         //   t.TestString();
        }
    }

    
}
