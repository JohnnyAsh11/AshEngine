using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.IO;
using ASHEngine.Interface.Reading.DTOs;

namespace ASHEngine.Interface.Reading
{
    public class JSONTestClass// : JsonReader
    {

        //public override bool Read()
        //{
        //
        //}

        public JSONTestClass(string filepath)
        {
            // Declaring Variables to the scope of the constructor.
            StreamReader? reader = null;
            string rawJSON = "";

            try
            {
                //
                string singleLine = "";
                reader = new StreamReader(filepath);

                while ((singleLine = reader.ReadLine()!) != null)
                {
                    rawJSON += singleLine;
                }
            }
            catch (Exception error)
            {
                // Using the thrown exception to throw a more meaningful exception.
                throw new Exception($"Reading Json data was not successful | ERROR: {error.Message}");
            }
            finally
            {
                if (!(reader is null))
                {
                    reader.Close();
                }
            }

            TestDataDTO? dto = JsonConvert.DeserializeObject<TestDataDTO>(rawJSON);


        }
    }
}
