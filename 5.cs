using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
/*
 * Описать класс "книга", содержащий следующие закрытые поля: автор, год издания, жанр.
 * Предусмотреть свойства для получения состояния объекта. Описать класс "домашняя библиотека".
 * Предусмотреть возможность 
    • работы с произвольным числом книг, 
    • поиска книги по какому-либо признаку (по автору, по году издания или жанру),
    • добавления книг в библиотеку,
    • удаления книг из нее,
    • доступа к книге по номеру.
 */

namespace _5
{
    class Program
    {
        static void Main()
        {

            Библиотека ДомашняяБиблиотека = new Библиотека();

            ДомашняяБиблиотека.Добавить("k", "Автор-1", "2020", "Жанр-1");
            char d;
            bool f = true;
            while(f)
            {
                Console.WriteLine("\n0 - Выйти" +
                    "\n1 - Добавить" +
                    "\n2 - Информация о книге" +
                    "\n3 - Список всех книг" +
                    "\n4 - Удалить книгу" +
                    "\n5 - Найти по названию");

                Console.Write("Действие: ");
                d = Char.Parse(Console.ReadLine());
                switch(d)
                {
                    case '0':
                        f = false;
                        break;
                    case '1':
                        ДомашняяБиблиотека.Добавить();
                        break;
                    case '2':
                        ДомашняяБиблиотека.Инфо();
                        break;
                    case '3':
                        ДомашняяБиблиотека.ВесьСписок();
                        break;
                    case '4':
                        ДомашняяБиблиотека.Удалить();
                        break;
                    case '5':
                        ДомашняяБиблиотека.Найти();
                        break;
                }
            }

        }
    }

    class Книга
    {

        public string Название { get; set; }
        string Автор { get; set; }
        string Год { get; set; }
        string Жанр { get; set; }

        public Книга(string название, string автор, string год, string жанр)
        {
            Название = название;
            Автор = автор;
            Год = год;
            Жанр = жанр;
        }

        public override string ToString()
        {
            string str = $"Название: {Название}\nАвтор: {Автор}\nГод: {Год}\nЖанр: {Жанр}\n";

            if (String.IsNullOrEmpty(str))
                return base.ToString();
            return str;
        }
    }

    class Библиотека
    {
        private List<Книга> СписокКниг;

        public Библиотека()
        {
            СписокКниг = new List<Книга>();
        }

        public void Добавить()
        {
            Console.Write("Сколько?: ");
            int count = Int32.Parse(Console.ReadLine());

            for (int i = 0; i < count; i++)
            {
                Console.Write("\nДобавление новой книги\nНазвание: ");
                string название = Console.ReadLine();
                Console.Write("Автор: ");
                string автор = Console.ReadLine();
                Console.Write("Год: ");
                string год = Console.ReadLine();
                Console.Write("Жанр: ");
                string жанр = Console.ReadLine();

                СписокКниг.Add(new Книга(название, автор, год, жанр));
            }
        }

        public void Добавить(string название, string автор, string год, string жанр)
        {
            СписокКниг.Add(new Книга(название, автор, год, жанр));
        }

        public IEnumerator GetEnumerator()
        {
            return СписокКниг.GetEnumerator();
        }

        public void ВесьСписок()
        {
            Console.WriteLine("\nСписок всех книг:");
            int i = 0;

            foreach (Книга книга in СписокКниг)
            {
                Console.WriteLine($"Номер: {i}");
                Console.WriteLine(книга.ToString());
                i++;
            }
        }

        public void Инфо()
        {
            Console.Write("По книге номер: ");
            int index = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"Номер: {index}");
            Console.WriteLine(СписокКниг[index].ToString());
        }

        public void Инфо(int index)
        {
            Console.WriteLine($"Номер: {index}");
            Console.WriteLine(СписокКниг[index].ToString());
        }

        public void Удалить()
        {
            Console.Write("Под каким номером удалить?: ");
            int deleteIndex = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"\nКнига под номером - {deleteIndex} с названием: {СписокКниг[deleteIndex].Название} успешно удалена");
            СписокКниг.RemoveAt(deleteIndex);
        }

        public void Удалить(int deleteIndex)
        {
            Console.WriteLine($"\nКнига под номером - {deleteIndex} с названием: {СписокКниг[deleteIndex].Название} успешно удалена");
            СписокКниг.RemoveAt(deleteIndex);
        }

        public Книга Найти()
        {
            Console.Write("Название: ");
            string name = Console.ReadLine();

            foreach (Книга книга in СписокКниг)
            {
                if (книга.Название == name)
                {
                    Console.WriteLine("Найдено");
                    Console.WriteLine(книга.ToString());
                    return книга;
                }
            }
            Console.WriteLine("Не Найдено");
            return null;
        }

        public Книга Найти(string Name)
        {
            foreach(Книга книга in СписокКниг)
            {
                if(книга.Название == Name)
                {
                    Console.WriteLine("Найдено");
                    return книга;
                }
            }
            Console.WriteLine("Не Найдено");
            return null;
            
        }

        public void НайтиВсе()
        {
            Console.Write("Название: ");
            string name = Console.ReadLine();

            foreach (Книга книга in СписокКниг)
            {
                if (книга.Название == name)
                {
                    Console.WriteLine("Найдено");
                    Console.WriteLine(книга.ToString());
                }
            }
            Console.WriteLine("Не Найдено");
        }

    }
}
