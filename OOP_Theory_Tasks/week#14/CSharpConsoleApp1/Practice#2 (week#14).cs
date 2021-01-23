using System;
class Program//i.e. any name you can assign
{
    private readonly int x, y;

    public Program(int x = 0, int y = 0)
    {
        this.x = x;
        this.y = y;
    }
    public void Sum()
    {
        Console.WriteLine("Sum: " + (x + y));
    }
    static void Main()
    {   
        Program obj = new Program(2);
        obj.Sum();
    }
}