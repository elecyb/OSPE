/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018-2019 Javier Pereda <https://github.com/elecyb>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

using System;
using System.Collections.Generic;
using System.Drawing;


namespace OSPE
{
    public sealed class Output
    {
        private static readonly Output instance = new Output();
        public static bool LogEnabled;

        public static Output Instance
        {
            get { return instance; }
        }

        /// <summary>
        /// Metodo general de logging, la salida la hace en LogForm
        /// </summary>
        /// <param name="str">Formated string; Ex: "String and parameters {0} {1} {2}"</param>
        /// <param name="args">Resto de la salida, los parametros que estan entre llaves {}; Ej: 10, var, "end"</param>
        public static void outString(string str, params object[] args)
        {
            if (!LogEnabled)
                return;

            LogForm.WriteLine(String.Format(str, args));
        }

        /// <summary>
        /// Metodo de logging de errores, la salida la hace en LogForm
        /// </summary>
        /// <param name="str">String formateado; Ej: "String and parameters {0} {1} {2}"</param>
        /// <param name="args">Resto de la salida, los parametros que estan entre llaves {}; Ej: 10, var, "end"</param>
        public static void outError(string str, params object[] args)
        {
            LogForm.WriteLine("ERROR: " + String.Format(str, args), Color.Red);
        }

    }
}
