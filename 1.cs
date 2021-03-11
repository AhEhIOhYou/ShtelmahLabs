
using System;

namespace _3
{
    class Program
    {

        static void Main(string[] args)
        {

            bool f1 = true, 
                f2 = false,
                search = true;

            int firstZeroIndexNumbers = 0,
                secondZeroIndexNumbers = 0,
                product = 1,
                count = 0,
                size = 20;

            int[] numbers = new int[size],
                bufArray = new int[numbers.Length];

            Random rnd = new Random();

            Console.WriteLine("Исходный массив: ");
            for (int i = 0; i < size; i++)
            {
                numbers[i] = rnd.Next(0, 6);
                Console.Write(numbers[i] + " ");
            }
            Console.WriteLine();

            int max = numbers[0];

            //Поиск максимального элемента
            foreach (int num in numbers)
                if (max < num)
                    max = num;

            //Алгоритм поиска индекса первого и второго нулей
            for (int i = 0; i < numbers.Length; i++)
                if (search)
                {
                    if (numbers[i] == 0 && f2)
                    {

                        secondZeroIndexNumbers = i;
                        f2 = false;
                        search = false;
                    }

                    if (numbers[i] == 0 && f1)
                    {
                        firstZeroIndexNumbers = i;
                        f1 = false;
                        f2 = true;
                    }
                } else
                    break;

            //Подсчет произведения
            if (firstZeroIndexNumbers == 0 && secondZeroIndexNumbers == 0)
                Console.WriteLine("Произведение между нулями подсчитать не удалось: необходимое количество нулей отсутсвует");
            else
                for (int i = firstZeroIndexNumbers + 1; i < secondZeroIndexNumbers; i++)
                {
                    product *= numbers[i];
                }

            //Циклы заполнения буферного массива четными и нечетными
            for (int i = 0; i < bufArray.Length; i++)
                if ((i - 1) % 2 != 0)
                {
                    bufArray[count] = numbers[i];
                    count++;
                }

            for (int i = 0; i < numbers.Length; i++)
                if ((i - 1) % 2 == 0)
                {
                    bufArray[count] = numbers[i];
                    count++;
                }

            Array.Copy(bufArray, numbers, bufArray.Length);

            Console.WriteLine("Преобразованный массив: ");
            foreach (int num in numbers)
                Console.Write(num + " ");
            Console.WriteLine();

            Console.WriteLine("Максимальный элеммент: " + max);

            Console.WriteLine("Произведение: " + product);

        }
    }
}
