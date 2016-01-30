using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace First_Non_Repeated_Character
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            bool repeated = true;
            char character = 'a';
            int index = 0;
            while (repeated && index < str.Length)
            {
                repeated = false;
                character = str[index];

                //loop through the rest of the string
                for (int i = 0; i < str.Length; i++)
                {
                    if (i != index && character == str[i])
                    {
                        repeated = true;
                        break;
                    }            
                }

                if (repeated)
                {
                    //continue to next character
                    index++;
                }
                else
                {
                    repeated = false;
                }
                
            }

            if (!repeated)
            {
                Console.WriteLine(character);
            }

            Console.ReadLine();    
        }
    }
}
