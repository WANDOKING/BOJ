using StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
using StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

string[] inputFirstLine = reader.ReadLine()!.Split();
int N = int.Parse(inputFirstLine[0]);
int M = int.Parse(inputFirstLine[1]);

int[] nums = Array.ConvertAll(reader.ReadLine()!.Split(), int.Parse);

int result = 0;

for (int i = 0; i < nums.Length - 2; ++i)
{
    for (int j = i + 1; j < nums.Length - 1; ++j)
    {
        for (int k = j + 1; k < nums.Length; ++k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > M)
            {
                continue;
            }

            if (sum > result)
            {
                result = sum;
            }
        }
    }
}

writer.Write(result);
