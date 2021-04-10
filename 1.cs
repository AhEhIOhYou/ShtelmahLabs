using System;
using System.Collections.Generic;

namespace _6
{
    class Program
    {

        public class Company
        {
            public string Name { get; set; }
            public Company(string n) => Name = n;
        }

        abstract class Tariff
        {
            public string Name { get; set; }
            public int SubCount { get; set; }
            public Tariff(string name, int subCount)
            {
                Name = name;
                SubCount = subCount;
            }
            public abstract int CalculateCostCall(int sec);
        }

        class PerSecondRate : Tariff
        {
            public int OneSecond { get; set; }
            public PerSecondRate(string name, int subCount, int price) : base(name, subCount) => OneSecond = price;
            public override int CalculateCostCall(int sec) => OneSecond * sec;
            public override bool Equals(object obj)
            {
                if (obj == null) return false;
                
                PerSecondRate t = obj as PerSecondRate;
                if (t == null) return false;

                return t.Name == Name && t.OneSecond == OneSecond && t.SubCount == SubCount;
            }
            public override string ToString()
            {
                return "[Название: " + Name + " Количество абонентов: " + SubCount + " Стоимость секунды: " + OneSecond + "]";
            }
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
            public override bool Equals(object obj)
            {
                if (obj == null) return false;

               PerMinuteRate t = obj as PerMinuteRate;
                if (t == null) return false;

                return t.Name == Name && t.OneMinute == OneMinute && t.SubCount == SubCount;
            }
            public override string ToString()
            {
                return "[Название: " + Name + " Количество абонентов: " + SubCount + " Стоимость минуты: " + OneMinute + "]" ;
            }
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
            Company C1 = new Company("Megafon");
            Subscriber S1 = new Subscriber("VDA", 89889657944, 21000);

            List<Tariff> tariffs = new List<Tariff>();
            tariffs.Add(new PerMinuteRate("T-Min", 12, 20));
            tariffs.Add(new PerSecondRate("T-Sec", 22, 2));

            foreach (Tariff t in tariffs)
            {
                Console.WriteLine(t.ToString() + "\nЦена разговора 80 секунд: " + t.CalculateCostCall(80));
                Console.WriteLine("Eq: " + t.Equals(t));
            }
            Console.WriteLine("Eq: " + tariffs[0].Equals(tariffs[1]));
        }
    }
}
