using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace _6
{
    class Program
    {

        public class Company
        {
            protected string Name { get; set; }
            private ArrayList _tariffsList = new ArrayList();
            public Company(string n) => Name = n;

            public void TariffAddPerMinuteRate(string n, int sc, int pr)
            {
                _tariffsList.Add(new PerMinuteRate(n, sc, pr));
            }
            
            public void TariffAddPerSecondRate(string n, int sc, int pr)
            {
                _tariffsList.Add(new PerSecondRate(n, sc, pr));
            }

            public void TariffShow()
            {
                foreach (var tariff in _tariffsList)
                {
                    Console.WriteLine(tariff.ToString());
                }
            }

            public void TariffSort()
            {
                _tariffsList.Sort();
            }

            public void Search(string className, string attr, string sValue)
            {
                foreach (Tariff tariff in _tariffsList)
                {
                    if (tariff.GetType().ToString() == className)
                    {
                        switch (attr)
                        {
                            case "Name":
                                if (tariff.Name == sValue)
                                    Console.WriteLine(tariff.ToString());
                                break;
                            case "SubCount":
                                if (tariff.SubCount == Int32.Parse(sValue))
                                    Console.WriteLine(tariff.ToString());
                                break;
                        }
                    }
                }
            }

        }

        public abstract class Tariff : IComparable
        {
            public string Name { get; set; }
            public int SubCount { get; set; }
            public Tariff(string name, int subCount)
            {
                Name = name;
                SubCount = subCount;
            }
            public abstract int CalculateCostCall(int sec);

            public int CompareTo(object o)
            {
                Tariff t = (Tariff) o;
                if (this.SubCount == t.SubCount) return 0;
                else if (this.SubCount > t.SubCount) return 1;
                else return -1;
            }

            public override bool Equals(object obj)
            {
                return (this.CompareTo(obj) == 0);
            }

            public static bool operator ==(Tariff t1, Tariff t2)
            {
                return (t1.CompareTo(t2) == 0);
            }

            public static bool operator !=(Tariff t1, Tariff t2)
            {
                return (t1.CompareTo(t2) != 0);
            }
        }

        class PerSecondRate : Tariff
        {
            public int OneSecond { get; set; }
            public PerSecondRate(string name, int subCount,
                int price) : base(name, subCount) => OneSecond = price;
            
            public override int CalculateCostCall(int sec) => OneSecond * sec;

            public override string ToString() => "[Название: " + Name + " Количество абонентов: " + SubCount +
                                                 " Стоимость секунды: " + OneSecond + "]";

        }

        class PerMinuteRate: Tariff
        {
            public int OneMinute { get; set; }
            public PerMinuteRate(string name, int subCount, int price) : base(name, subCount) => OneMinute = price;
            public override int CalculateCostCall(int sec)
            {
                var min = 0;
                while (sec > 0)
                {
                    min++;
                    sec -= 60;
                }
                return min * OneMinute;
            }
            public override string ToString() => "[Название: " + Name + " Количество абонентов: " + SubCount + " Стоимость минуты: " + OneMinute + "]" ;
        }

        public class Subscriber
        {
            public string Initials { get; set; }
            public long PhoneNum { get; set; }
            public int Balance { get; set; }
            public Subscriber(string init, long num, int b)
            {
                Initials = init;
                PhoneNum = num;
                Balance = b;
            }
        }

        static void Main(string[] args)
        {
            Company c1 = new Company("Megafon");
            Subscriber s1 = new Subscriber("VDA", 89889657944, 21000);
            
            c1.TariffAddPerMinuteRate("t-min", 1200, 200);
            c1.TariffAddPerMinuteRate("t-kek", 1200, 20);
            c1.TariffAddPerSecondRate("t-sec", 200, 12);
            c1.TariffAddPerSecondRate("t-sec-l", 1200, 12);
            c1.TariffAddPerMinuteRate("t-min2", 100,190);
            
            c1.TariffShow();
            c1.TariffSort();
            Console.WriteLine("СОРТИРУЕМ ПО КОЛИЧЕСТВУ АБОНЕНТОВ");
            c1.TariffShow();
            
            while (true)
            {
                Console.Write("Произвести поиск? (y:n): ");
                var key = Console.ReadLine();
                switch (key)
                {
                    case "y":
                        bool run = true;
                        while (run)
                        {
                            Console.Write("Класс экземпляра - `PerMinuteRate` или `PerSecondRate` (выход - exit):");
                            var searchClassName = Console.ReadLine();
                            string searchClassProp;
                            string searchValue;
                            Tariff findTariff;
                            switch (searchClassName)
                            {
                                case "PerMinuteRate":
                                    Console.Write("Найти - `Name`, `SubCount`: ");
                                    searchClassProp = Console.ReadLine();
                                    switch (searchClassProp)
                                    {
                                        case "Name":
                                            Console.Write("Искомое имя: ");
                                            searchValue = Console.ReadLine();
                                            c1.Search("_6.Program+PerMinuteRate", "Name", searchValue);
                                            break;
                                        case "SubCount":
                                            Console.Write("Искомое количество абонентов: ");
                                            searchValue = Console.ReadLine();
                                            c1.Search("_6.Program+PerMinuteRate", "SubCount", searchValue);
                                            break;
                                    }
                                    break;
                                case "PerSecondRate":
                                    Console.Write("Найти - `Name`, `SubCount`: ");
                                    searchClassProp = Console.ReadLine();
                                    switch (searchClassProp)
                                    {
                                        case "Name":
                                            Console.Write("Искомое имя: ");
                                            searchValue = Console.ReadLine();
                                            c1.Search("_6.Program+PerSecondRate", "Name", searchValue);
                                            break;
                                        case "SubCount":
                                            Console.Write("Искомое количество абонентов: ");
                                            searchValue = Console.ReadLine();
                                            c1.Search("_6.Program+PerSecondRate", "SubCount", searchValue);
                                            break;
                                    }
                                    break;
                                case "exit":
                                    run = false;
                                    break;
                            }
                        }
                        break;
                    case "n":
                        return;
                }
            }
            
            Console.ReadKey();
        }
    }
}
