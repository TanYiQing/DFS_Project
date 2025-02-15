using System;
using System.Runtime.InteropServices;
using System.Windows;

namespace frontend
{
   public partial class MainWindow : Window
   {
      // Import function1.dll
      [DllImport("function1.dll", CallingConvention = CallingConvention.Cdecl)]
      public static extern void function_from_function1();

      public MainWindow()
      {
         InitializeComponent();
      }

      private void OnButtonClick(object sender, RoutedEventArgs e)
      {
         try
         {
            function_from_function1();
            OutputText.Text = "Called function1 successfully!";
         }
         catch (Exception ex)
         {
            OutputText.Text = $"Error: {ex.Message}";
         }
      }
   }
}
