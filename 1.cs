using System;
using System.IO;

namespace _4
{
    class Program
    {
        static void Main(string[] args)
        {            
            string input = File.ReadAllText(@"C:\\Users\\Lenovo\\Desktop\\VolSU project\\Codding\\C++\\4\\4\\text.txt").Replace("\n", " ");
            
            Console.WriteLine("Исходный текст из файла: " + input + "\n");

            string[] str = input.Split(new Char[] { ' ', ',', '.', ':', '!', '?', ';' }, StringSplitOptions.RemoveEmptyEntries);
            
            int maxlen = 0, index = 0, count = 0;

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i].Length > maxlen)
                {
                    maxlen = str[i].Length;
                    index = i;
                }

            }
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == str[index]) count++;
            }

            Console.Write($"Самое длинное слово: {str[index]}\nВстретилось: {count} раз\n");
        }
    }
}
