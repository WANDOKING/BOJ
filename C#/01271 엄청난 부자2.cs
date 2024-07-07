using System.Numerics;

string[] inputs = Console.ReadLine()!.Split();
BigInteger n = BigInteger.Parse(inputs[0]);
BigInteger m = BigInteger.Parse(inputs[1]);

Console.WriteLine(n / m);
Console.WriteLine(n % m);
