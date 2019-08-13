using System;
using System.Collections.Generic;
using System.Linq;
namespace Test
{
    class Program
    {
        static string input;
        static List<string> result = new List<string>();

        static void Main()
        {
            // get s
            input = Console.ReadLine();

            int depth_cur = 0;
            int count = 0;
            int[] brac = new int[20];
            int[] depth = new int[10];

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] == '(')
                {
                    depth[depth_cur] = i;
                    depth_cur++;
                }
                else if (input[i] == ')')
                {
                    depth_cur--;
                    brac[count] = depth[depth_cur];
                    brac[count + 1] = i;
                    count += 2;
                    depth[depth_cur] = -1;
                }
            }


            for (int i = 0; i < 20; i += 2)
            {
                Check(input, brac, i);
            }

            result.Sort();
            for (int i = 0; i < result.Count; i++)
            {
                Console.WriteLine(result[i]);
            }
        }

        static void Check(string _input, int[] brac, int i)
        {
            if (i < 20 && brac[i + 1] > 0)
            {
                _input = _input.Remove(brac[i], 1);
                _input = _input.Insert(brac[i], "a");
                _input = _input.Remove(brac[i + 1], 1);
                _input = _input.Insert(brac[i + 1], "a");

                for (int j = i + 2; j < 20; j += 2)
                {
                    Check(_input, brac, j);
                }

                string _temp = _input;
                _temp = _temp.Replace("a", "");

                if (!result.Contains(_temp))
                    result.Add(_temp);
            }
        }

    }

}
