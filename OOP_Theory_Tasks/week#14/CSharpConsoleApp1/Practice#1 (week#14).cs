using System;

namespace CSharpConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter any value: ");
            Int32 value;//Alternate: Int32 value= Convert.ToInt32(Console.ReadLine()); (doesn't handles exception)
            Int32.TryParse(Console.ReadLine(), out value);//i.e. also handles exception
            if (value < 20)
                Console.WriteLine("Hello World, value: " + value);
            else
                Console.WriteLine("Hello World!");  
        }
    }
}
