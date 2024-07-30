string input = Console.ReadLine()!;

int blockCount = 1;

for (int i = 1; i < input.Length; ++i)
{
    if (input[i - 1] != input[i])
    {
        blockCount++;
    }
}

Console.WriteLine(blockCount / 2);
