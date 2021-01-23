using System;
namespace StaticInCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(HistoryTeacher.Subject);
            HistoryTeacher.Name = "Ibrahim Farooqi";
            HistoryTeacher.School = "NUCES FAST";
            HistoryTeacher.Rank = 2;
            HistoryTeacher.Years = 5;
            Console.WriteLine(HistoryTeacher.Name);
            Console.WriteLine(HistoryTeacher.School);
            Console.WriteLine("Score: "+HistoryTeacher.CalculateScore(3, 5)+"\nPress any key to continue...");
            Console.ReadKey();
        }
    }
    public static class HistoryTeacher
    {
        // static field  
        public static string Subject = "History";
        // private fields  
        private static string name;
        private static string school;
        private static int rank;
        private static int years;
        // static properties  
        public static int Years { get => years; set => years = value; }
        public static int Rank { get => rank; set => rank = value; }
        public static string School { get => school; set => school = value; }
        public static string Name { get => name; set => name = value; }
        // static method  
        public static int CalculateScore(int _rank = 0, int _years = 0)
        {
            if (_rank != 0 && _years != 0)
                return _rank * _years;
            return rank * years;
        }
    }
}