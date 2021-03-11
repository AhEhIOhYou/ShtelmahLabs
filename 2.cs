
using System;
using System.Collections.Generic;

namespace _3
{
    class Program
    {

        static void Main(string[] args)
        {
            int size = 6;
            int[,] matrix = new int[size, size];

            var allowedCol = new List<int>();
            int sum = 0;

            bool contains = true;

            Random rnd = new Random();

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    matrix[i, j] = rnd.Next(-9, 9);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    Console.Write(matrix[i, j] + "\t");
                Console.WriteLine();
            }

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    if (matrix[j, i] < 0)
                        contains = false;

                if (contains)
                    allowedCol.Add(i);

                contains = true;
            }

            if (allowedCol.Count == 0)
                Console.WriteLine("Матрица не содержит полностью положительных столбцов");
            else
                foreach (int col in allowedCol)
                {
                    sum = 0;
                    for (int i = 0; i < size; i++)
                        if (col == i)
                        {
                            for (int j = 0; j < size; j++)
                                sum += matrix[j, i];

                            Console.WriteLine("Сумма столбца: " + (i + 1) + " = " + sum);
                        }
                }

            int max = matrix[0, 0],
                trueMax = 0;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (max == matrix[i, j])
                    {
                        trueMax = max;
                    }
                    if (matrix[i, j] > max)
                    {
                        max = matrix[i, j];
                    }
                }
            }

            Console.WriteLine("Максимальный, настоящий: " + trueMax);

        }
    }
}
