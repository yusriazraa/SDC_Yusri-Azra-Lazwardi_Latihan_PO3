/*  Nama    : Yusri Azra Lazwardi
    NPM     : 432007006200083
    Kelas   : 1C
    Desk    : Latihan 3 tentang Struct (Record)
*/
// Header File
#include <iostream>     //Tambah iostream
#include <iomanip>      //Tambah Iomanip
#include <string.h>     //Tambah String.h
#include "stdlib.h"     //Tambah stdlib.h
#include "conio.h"      //Tambah conio.h

using namespace std;
typedef unsigned short int angka;

//Deklarasi Struct (record)

struct tanggal {        //menambahkan Struct tanggal
    angka tanggal, tahun;
    string bulan;
};

struct alamat {         //menambahkan Struct alamat
    angka kode_pos;
    string jalan, kota;
};

struct keljurusan {     //menambahkan Struct kel
    angka id_jurusan;
    string jurusan;
};

struct Data_Nilai {     //menambahkan Struct data_nilai Mahasiswa
    string pti, dasprog, strukdat, matematika, binggris;
};

struct kelstatus {      //menambahkan Struct tanggal
    angka id_status;
    string status;
};

struct data_mhs {       //menambahkan Struct data Mahasiswa
    alamat almt;
    tanggal lahir;
    keljurusan katjur;
    kelstatus katsat;
    Data_Nilai nilai;
    string nama, npm;
};

// menambahkan variabel global
char ulangi;
angka i;
data_mhs mhs[14];

// deklarasi/protoype fungsi ke fungsi
void garis (char,int);
void header ();
void cetakjudul ();
void inputdata_mhs ();
void laporansemua ();
void laporanstatus ();
void laporanjurusan ();
void cetaklaporan ();
void footer ();

// program utama
int main () {

    i=0;
    ulangi ='y';
    while (ulangi == 'Y' || ulangi == 'y')
        {
        system ("cls");
        inputdata_mhs ();
        cout << "Tambah Data Lagi (Y/T) ? = "; cin >> ulangi;
        i++;
        } // akhir dari while
    cout << endl;
    cout << "Tekan Tombol Enter untuk Melihat Laporan!!";
    getch ();
    cetaklaporan ();
    return 0;
    } // akhir dari program utama

// definisi fungsi
void garis (char karakter, int byk)
    { // awal dari fungsi garis
        for (int i=0; i<=byk; i++)
        {
            cout << karakter;
        }
        cout << endl;
    } // akhir dari fungsi garis

void header ()
    {// awal dari fungsi header
    cout << "\t\t\t\t\t\t\t\t ~~~~~ Laporan Data Mahasiswa ~~~~~" << endl;
    cout << endl;
    garis ('_', 120);
    cout << "|    |                |          |        |                             Mata Kuliah                           |" << endl;
    cout << "| No | Nama Mahasiswa | Jurusan  | Status |===================================================================|" << endl;
    cout << "|    |                |          |        | PTI | Dasar Pemrograman | Struktur Data | Matematika | B. Inggris |" << endl;
    garis ('_', 120);
    } // akhir dari fungsi header

void cetakjudul ()
{
    garis ('_', 60);
    cout << "\t\t Program Data Mahasiswa " << endl;
    garis ('_', 60);
} // akhir dari fungsi cetakjudul

void inputdata_mhs ()
{ // awal dari fungsi input data mahasiswa
    system ("cls");
    cetakjudul ();// menambahkan fungsi cetajudul ke dalam fungsi inputdata_mhs

    cout << "Input Data Ke - " << i+1 << endl  << endl;
    cout << "NPM             : "; cin >> mhs[i].npm;
    cin.ignore();
    cout << "Nama Mahasiswa  : "; getline (cin, mhs[i].nama);
    cout << endl;
    cout << " ~ Tanggal Lahir Mahasiswa ~" << endl;
    cout << "   Tanggal      : "; cin >> mhs[i].lahir.tanggal;
    cout << "   Bulan        : "; cin >> mhs[i].lahir.bulan;
    cout << "   Tahun        : "; cin >> mhs[i].lahir.tahun;
    cout << endl;
    cout << " ~ Input Alamat Mahasiswa ~" << endl;
    cout << "   Jalan        : "; cin >> mhs[i].almt.jalan;
    cin.ignore();
    cout << "   Kota/Kab     : "; cin >> mhs[i].almt.kota;
    cout << "   Kode Pos     : "; cin >> mhs[i].almt.kode_pos;
    cout << endl;
    cout << "pilih salah satu!" << endl;
    cout << "1. S1 - TI" << endl;
    cout << "2. S1 - SI" << endl;
    cout << "3. S1 - KA" << endl;
    cout << "4. D3 - TKJ" << endl;
    cout << "Jurusan [1-4]   : "; cin >> mhs[i].katjur.id_jurusan;
    // awal switch untuk pilihan jurusan
    switch (mhs[i].katjur.id_jurusan)
    {// awal dari switch pilihan jurusan
        case 1 :
            mhs[i].katjur.jurusan = "S1 - TI";
        break;
        case 2 :
            mhs[i].katjur.jurusan = "S1 - SI";
        break;
        case 3 :
            mhs[i].katjur.jurusan = "S1 - KA";
        break;
        case 4 :
            mhs[i].katjur.jurusan = "D3 - TKJ";
        break;
        default :
        mhs [i].katjur.jurusan = "Error silakan coba lagi 'isi dengan angka 1 sampai 4 ya!'";
    } // akhir dari switch pilihan jurusan
    cout << endl;
    cout << "pilih salah satu!" << endl;
    cout << "1. Aktif" << endl;
    cout << "2. OFF" << endl;
    cout << "3. CUTI" << endl;
    cout << "4. LULUS" << endl;
    cout << "Status [1-4]     : "; cin >> mhs[i].katsat.id_status;
    switch (mhs[i].katsat.id_status)
    { // awal dari switch pilihan status
        case 1 :
        mhs[i].katsat.status = "Aktif";
        break;
        case 2 :
        mhs[i].katsat.status = "OFF";
        break;
        case 3 :
        mhs[i].katsat.status = "CUTI";
        break;
        case 4 :
        mhs[i].katsat.status = "LULUS";
        break;
        default :
        mhs[i].katsat.status = "Error  silakan coba lagi 'isi dengan angka 1 sampai 4 ya!'";
    }  // akhir dari switch pilihan status

    cout << endl << endl;
    cout << " ~ Nilai Mata Kuliah Mahasiswa - " << mhs[i].nama << " - ~" << endl;
    cout << "   PTI                 : "; cin >> mhs[i].nilai.pti;
    cout << "   Dasar Pemrograman   : "; cin >> mhs[i].nilai.dasprog;
    cout << "   Struktur Data       : "; cin >> mhs[i].nilai.strukdat;
    cout << "   Matematika          : "; cin >> mhs[i].nilai.matematika;
    cout << "   B. Inggris          : "; cin >> mhs[i].nilai.binggris;
    cout << endl;
} // akhir dari fungsi input data mahasiswa

    void laporansemua()
    {// awal dari fungsi laporan semua
        system ("cls");
        cout << endl;
        header (); // menambahkan fungsi header ke dalam fungsi laporan semua
        for (int a=0; a<i; a++)
        {// awal dari for untuk menampilkan data yagn telah di input
            cout <<"| " << setiosflags(ios::left) << setw(2) << a+1;
            cout <<" | " << setiosflags(ios::left) << setw(14) << mhs[a].nama;
            cout <<" | " << setiosflags(ios::left) << setw(8) << mhs[a].katjur.jurusan;
            cout <<" | " << setiosflags(ios::left) << setw(6) << mhs[a].katsat.status;
            cout <<" | " << setiosflags(ios::left) << setw(3) << mhs[a].nilai.pti;
            cout <<" |        " << setiosflags(ios::left) << setw(10) << mhs[a].nilai.dasprog;
            cout <<" |      " << setiosflags(ios::left) << setw(8) << mhs[a].nilai.strukdat;
            cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.matematika;
            cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.binggris;
            cout <<" |"  << endl;
        }// akhir dari for untuk menampilkan data yagn telah di input
        footer ();// menambahkan fungsi footer ke dalam fungsi laporan semua
    }// akhir dari fungsi laporan semua

    void laporanstatus ()
    {// awal dari fungsi laporanstatus
        angka pilihan;
        system ("cls");
        cout << "Ketik Pilihan [1-4] = "; cin >> pilihan;
        cout << endl;
        angka x=0;
        header ();// menambahkan fungsi header ke dalam fungsi laporanstatus
        for (int a=0; a<i; a++)
        {// awal dari for untuk menampilkan laporan status
            if (mhs[a].katsat.id_status == pilihan)
            {// awal dari if
                cout <<"| " << setiosflags(ios::left) << setw(2) << x+1;
                cout <<" | " << setiosflags(ios::left) << setw(14) << mhs[a].nama;
                cout <<" | " << setiosflags(ios::left) << setw(8) << mhs[a].katjur.jurusan;
                cout <<" | " << setiosflags(ios::left) << setw(6) << mhs[a].katsat.status;
                cout <<" | " << setiosflags(ios::left) << setw(3) << mhs[a].nilai.pti;
                cout <<" |        " << setiosflags(ios::left) << setw(10) << mhs[a].nilai.dasprog;
                cout <<" |      " << setiosflags(ios::left) << setw(8) << mhs[a].nilai.strukdat;
                cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.matematika;
                cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.binggris;
                cout <<" |"  << endl;
                x++;
            }// akhir dari if

        }// akhir dari for untuk menampilkan laporan status
        footer ();// menambahkan fungsi footer ke dalam fungsi laporanstatus
    }// akhir dari fungsi laporanstatus

    void laporanjurusan ()
    {// awal dari fungsi laporanjurusan
        angka pilihan;
        system ("cls");
        cout << "Ketik Pilihan [1-4] = "; cin >> pilihan;
        cout << endl;
        angka y=0;
        header ();// menambahkan fungsi header ke dalam fungsi laporanjurusan
        for (int a=0; a<i; a++)
        {// awal dari for untuk menampilkan laporan jurusan
            if (mhs[a].katsat.id_status == pilihan)
            {// awal dari if
                cout <<"| " << setiosflags(ios::left) << setw(2) << y+1;
                cout <<" | " << setiosflags(ios::left) << setw(14) << mhs[a].nama;
                cout <<" | " << setiosflags(ios::left) << setw(8) << mhs[a].katjur.jurusan;
                cout <<" | " << setiosflags(ios::left) << setw(6) << mhs[a].katsat.status;
                cout <<" | " << setiosflags(ios::left) << setw(3) << mhs[a].nilai.pti;
                cout <<" |        " << setiosflags(ios::left) << setw(10) << mhs[a].nilai.dasprog;
                cout <<" |      " << setiosflags(ios::left) << setw(8) << mhs[a].nilai.strukdat;
                cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.matematika;
                cout <<" |     " << setiosflags(ios::left) << setw(6) << mhs[a].nilai.binggris;
                cout <<" |"  << endl;
                y++;
            }// akhir dari if
        }// akhir dari for untuk menampilkan laporanjurusan
        footer ();
    }// akhir dari fungsi laporanjurusan

    void cetaklaporan ()
    {// awal dari fungsi cetaklaporan
        laporanYAL:
        system ("cls");
        char pilihan,menu;
            cout << endl;
            cout << " ~ Pilih Cetak Laporan ~" << endl;
            cout << "   A. Tampilkan Semua" << endl;
            cout << "   B. Tampilkan Status" << endl;
            cout << "   C. Tampilkan Jurusan" << endl;
            cout << endl;
            cout << "   Pilih [A-C] : "; cin >> pilihan;
            switch (pilihan)
            {// awal dari switch pilihan
                case 'A' : case 'a' :
                    laporansemua ();
                    break;
                case 'B' : case 'b':
                    laporanstatus ();
                    break;
                case 'C' : case 'c' :
                    laporanjurusan ();
                    break;
                default :
                    cout << "Error silakan ketikan A-C" << endl;
                    goto laporanYAL;
            }// akhir dari switch pilihan
            cout << endl;
            cout << "Ketik [O : Menu Utama] atau [X : Kembali] = "; cin >> menu;
            if(menu == 'O' || menu == 'o')
            {// awal dari if menu
                cin.ignore ();
                goto laporanYAL;
            }// akhir dari if menu
            else if (menu == 'X' || menu == 'x')
            {// awal dari else if menu
                system("cls");
                inputdata_mhs();
            }// akhir dari else if menu
            else
            {// awal dari else menu
                footer();
            }// akhir dari else menu
    }// akhir dari fungsi cetaklaporan

    void footer ()
    {// awal dari fungsi footer
        garis('_', 120);
        cout << "\t\t\t\t\t\t\t ~~~ TERIMA KASIH ~~~" << endl;
    }// akhir dari fungsi footer
