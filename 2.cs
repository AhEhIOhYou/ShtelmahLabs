using System;
using System.IO;
using System.Text.RegularExpressions;

namespace _4
{
    class Program
    {
        //Задание 1 - Найдите строчки, в которых естьслова, которые начинаются на гласную (\b—граница слова);;
        static void Find1(string input)
        {
            Regex re = new Regex(@"\b[eyuioaEYUIOAуеаоэяиюУЕЭАОЭЯИЮ]+[а-яА-Яa-zA-Z]*\b");

            MatchCollection m = re.Matches(input);

            Console.WriteLine("Позиции необходимых подстрок:");
            foreach (Match ma in m)
            {
                Console.WriteLine(ma.Index + " - " + ma.Value);
            }
        }

        //Задание 2 - Строки, содержащие две буквы из множества {«x», «y», «z»}, между которыми от 5 до 17 символов.
        //Пример строк, которые подходят: «xabcabcz», «zzzzzzzzzzzzzzzzzz». Пример строк, которые не подходят: «xx», «xyz», «zwzwwz».
        static void Find2(string input)
        {
            Regex re = new Regex(@"\b[xyz]\w{5,17}[xyz]\b");

            MatchCollection m = re.Matches(input);

            Console.WriteLine("\nСтроки, что удовлетворяют критерию:");
            foreach (Match ma in m)
            {
                Console.WriteLine(ma.Value);
            }
        }

        //Задание 3 - Заменить все числа кратные 10 на их частное от деления на 10. В этой задаче на вход подаются числа, разделенные пробелами.
        //Примеры замен: «1 2 10 12 20 123 239 566 12800» → «1 2 1 12 2 123 239 566 1280»
        static void Find3(string input)
        {
            int count = 0;
            Regex re = new Regex(@"\d+");

            MatchCollection m = re.Matches(input);
            
            for (int i = 0; i < m.Count; i++)
            {
                int buf = Int32.Parse(m[i].Value);
                if (buf % 10 == 0)
                {
                    count++;
                    buf /= 10;
                    Regex myReg = new Regex(m[i].Value); 
                    input = myReg.Replace(input, buf.ToString());
                }
                
            }
            Console.WriteLine("\nПреобразуем и получим:\n" + input + "\nКоличество замен: " + count);
        }

        static void Main(string[] args)
        {
            string input;

            using (StreamReader stream = new StreamReader(@"C:\\Users\\Lenovo\\Desktop\\VolSU project\\Codding\\C++\\4\\4\\text.txt"))
            {
                input = stream.ReadToEnd();
            }

            Console.WriteLine("Исходный текст из файла:\n" + input + "\n");

            Find1(input);
            Find2(input);
            Find3(input);
        }
    }
}
