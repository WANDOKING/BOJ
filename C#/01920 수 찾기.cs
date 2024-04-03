using System.Collections;
using System.Text;

int N = int.Parse(Console.ReadLine()!);
string[] inputNumbers = Console.ReadLine()!.Split();

int[] numbers = new int[N];

for (int i = 0; i < N; ++i)
{
    numbers[i] = int.Parse(inputNumbers[i]);
}

Array.Sort(numbers);

int M = int.Parse(Console.ReadLine()!);
string[] inputTargetNumbers = Console.ReadLine()!.Split();

StringBuilder result = new StringBuilder();

for (int i = 0; i < M; ++i)
{
    int targetNumber = int.Parse(inputTargetNumbers[i]);

    if (Array.BinarySearch(numbers, targetNumber) >= 0)
    {
        result.AppendLine("1");
    }
    else
    {
        result.AppendLine("0");
    }
}

Console.Write(result.ToString());
