using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextToNumber
{
    class Program
    {
    
        static void Main(string[] args)
        {
            Dictionary<string, int> conversion = text_number_dictionary();

            string line = Console.ReadLine();
            string[] words = null;

            words = line.Split(' ');

            List<int> num = new List<int>() { 0 };
            int i = 0;
            bool isNegative = false;

            foreach (var item in words)
            {
                //Console.WriteLine("text = {0}, number = {1}", item, conversion[item]);

                if(new[]{"hundred", "thousand", "million"}.Contains(item))
                {
                    num[i] *= conversion[item];
                    num.Add(0);
                    i++;
                }
                else if (item == "negative")
                {
                    isNegative = true;
                }
                else
                {
                    num[i] += conversion[item];
                }
                //Console.WriteLine(num[i]);
            }

            int sum = 0;
            foreach (var item in num)
            {
                sum += item;
            }
            if (isNegative)
            {
                sum *= -1;
            }

            Console.WriteLine(sum);

        }

        static Dictionary<string, int> text_number_dictionary()
        {
            Dictionary<string, int> conversion = new Dictionary<string, int>();

            conversion.Add("negative", -1); //TODO: Special Case
            conversion.Add("zero", 0); //TODO: Might be a special case

            conversion.Add("one", 1);
            conversion.Add("two", 2);
            conversion.Add("three", 3);
            conversion.Add("four", 4);
            conversion.Add("five", 5);
            conversion.Add("six", 6);
            conversion.Add("seven", 7);
            conversion.Add("eight", 8);
            conversion.Add("nine", 9);

            conversion.Add("ten", 10);

            conversion.Add("eleven", 11);
            conversion.Add("twelve", 12);
            conversion.Add("thirteen", 13);
            conversion.Add("fourteen", 14);
            conversion.Add("fifteen", 15);
            conversion.Add("sixteen", 16);
            conversion.Add("seventeen", 17);
            conversion.Add("eighteen", 18);
            conversion.Add("nineteen", 19);

            conversion.Add("twenty", 20);
            conversion.Add("thirty", 30);
            conversion.Add("fourty", 40);
            conversion.Add("fifty", 50);
            conversion.Add("sixty", 60);
            conversion.Add("seventy", 70);
            conversion.Add("eighty", 80);
            conversion.Add("ninety", 90);

            conversion.Add("hundred", 100);
            conversion.Add("thousand", 1000);
            conversion.Add("million", 1000000);

            return conversion;
        }

    }
}
