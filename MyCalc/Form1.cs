using System;
using System.Globalization;
using System.Windows.Forms;

namespace MyCalc
{
    public partial class Calculator : Form
    {
        public Calculator()
        {
            InitializeComponent();
        }


        private void Exit(object sender, EventArgs e)
        {
            Close();
        }

        private void Add(object sender, EventArgs e)
        {
            Calculate('+');
        }

        private void Sub(object sender, EventArgs e)
        {
            Calculate('-');
        }

        private void Mul(object sender, EventArgs e)
        {
            Calculate('*');
        }

        private void Div(object sender, EventArgs e)
        {
            Calculate('/');
        }

        private void Calculate(char operand)
        {
            double z = double.NaN;
            try
            {
                double x = Convert.ToDouble(FirsOperand.Text);
                double y = Convert.ToDouble(SecondOperand.Text);
                switch (operand)
                {
                    case '+':
                        z = x + y;
                        break;
                    case '-':
                        z = x - y;
                        break;
                    case '*':
                        z = x * y;
                        break;
                    case '/':
                        z = x / y;
                        break;
                }

                Result.Text = Convert.ToString(z, CultureInfo.InvariantCulture);
            }
            catch (Exception)
            {
                MessageBox.Show("Error in operands !",
                    "Calculator Error", MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }
    }
}