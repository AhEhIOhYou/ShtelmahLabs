using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
/*
 * Описатькласс "книга", содержащий следующие закрытые поля: автор, год издания, жанр.
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

            ДомашняяБиблиотека.Добавить();
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

        public void оКниге()
        {
            Console.WriteLine($"Название: {Название}\nАвтор: {Автор}\nГод: {Год}\nЖанр: {Жанр}\n");
        }
    }

    class Библиотека
    {
        private List<Книга> Книги;

        public Библиотека()
        {
            Книги = new List<Книга>();
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

                Книги.Add(new Книга(название, автор, год, жанр));
            }
        }

        public void Добавить(string название, string автор, string год, string жанр)
        {
            Книги.Add(new Книга(название, автор, год, жанр));
        }

        public IEnumerator GetEnumerator()
        {
            return Книги.GetEnumerator();
        }

        public void ВесьСписок()
        {
            Console.WriteLine("\nСписок всех книг:");
            int i = 0;

            foreach (Книга книга in Книги)
            {
                Console.WriteLine($"Номер: {i}");
                книга.оКниге();
                i++;
            }
        }

        public void Инфо()
        {
            Console.Write("По книге номер: ");
            int index = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"Номер: {index}");
            Книги[index].оКниге();
        }

        public void Инфо(int index)
        {
            Console.WriteLine($"Номер: {index}");
            Книги[index].оКниге();
        }

        public void Удалить()
        {
            Console.Write("Под каким номером удалить?: ");
            int deleteIndex = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"\nКнига под номером - {deleteIndex} с названием: {Книги[deleteIndex].Название} успешно удалена");
            Книги.RemoveAt(deleteIndex);
        }

        public void Удалить(int deleteIndex)
        {
            Console.WriteLine($"\nКнига под номером - {deleteIndex} с названием: {Книги[deleteIndex].Название} успешно удалена");
            Книги.RemoveAt(deleteIndex);
        }

        public string Найти(string Name)
        {
            Книга check = Книги.Find(x => x.Название.Contains(Name));
            if (check != null)
            {
                check.оКниге();
                return "Нашлось!";
            }

            return "Не нашлось :(";
        }

    }
}
