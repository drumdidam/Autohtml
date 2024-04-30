#include "MyForm.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <vector>
#include <iostream>
#include <xlsxio_read.h>
#include <xlsxio_version.h>
#include <xlsxio_write.h>

using namespace std;

using namespace System;
using namespace System::Windows::Forms;

vector<vector<string>> ReadExcel(const char* filename)
{
    vector<vector<string>> data;

    xlsxioreader xls = xlsxioread_open(filename);
    if (!xls)
    {
        cerr << "Fehler beim Öffnen der Excel-Datei." << endl;
        return data;
    }

    xlsxioreadersheet sheet = xlsxioread_sheet_open(xls, NULL, XLSXIOREAD_SKIP_EMPTY_ROWS);
    if (!sheet)
    {
        cerr << "Fehler beim Öffnen des Arbeitsblatts." << endl;
        xlsxioread_close(xls);
        return data;
    }

    while (xlsxioread_sheet_next_row(sheet))
    {
        vector<string> row;
        xlsxioread_sheet_next_row(sheet);

        while (xlsxioread_sheet_next_cell(sheet)!= NULL)
        {
            const char* cell_value = xlsxioread_sheet_next_cell(sheet);
            row.push_back(cell_value);
        }

        data.push_back(row);
    }

    xlsxioread_sheet_close(sheet);
    xlsxioread_close(xls);

    return data;
}



[STAThread]



int main(array<String^>^ args) {
    
    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    AutoHTML::MyForm^ form = gcnew AutoHTML::MyForm();
    Application::Run(form); 
    return 0;


}