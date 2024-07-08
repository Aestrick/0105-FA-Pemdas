#include <iostream>
using namespace std;
class MataKuliah {
protected:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    MataKuliah() : presensi(0.0), activity(0.0), exercise(0.0), tugasAkhir(0.0) {}

    virtual void namaMataKuliah() = 0;
    virtual void inputNilai() = 0;
    virtual float hitungNilaiAkhir() = 0;
    virtual void cekKelulusan() = 0;

    void setPresensi(float nilai) { presensi = nilai; }
    float getPresensi() { return presensi; }
    void setActivity(float nilai) { activity = nilai; }
    float getActivity() { return activity; }
    void setExercise(float nilai) { exercise = nilai; }
    float getExercise() { return exercise; }
    void setTugasAkhir(float nilai) { tugasAkhir = nilai; }
    float getTugasAkhir() { return tugasAkhir; }
};

class Pemrograman : public MataKuliah {
public:
    void namaMataKuliah() override {
        cout << "Pemrograman" << endl;
    }

    void inputNilai() override {
        cout << "Masukkan nilai presensi: ";
        cin >> presensi;
        cout << "Masukkan nilai activity: ";
        cin >> activity;
        cout << "Masukkan nilai exercise: ";
        cin >> exercise;
        cout << "Masukkan nilai tugas akhir: ";
        cin >> tugasAkhir;
    }

    float hitungNilaiAkhir() override {
        return (presensi * 0.1) + (activity * 0.2) + (exercise * 0.3) + (tugasAkhir * 0.4);
    }

    void cekKelulusan() override {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat, Anda dinyatakan Lulus" << endl;
        }
        else {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

class Jaringan : public MataKuliah {
public:
    void namaMataKuliah() override {
        cout << "Jaringan" << endl;
    }

    void inputNilai() override {
        cout << "Masukkan nilai activity: ";
        cin >> activity;
        cout << "Masukkan nilai exercise: ";
        cin >> exercise;
    }

    float hitungNilaiAkhir() override {
        return (activity * 0.4) + (exercise * 0.5);
    }

    void cekKelulusan() override {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat, Anda dinyatakan Lulus" << endl;
        }
        else {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
};

int main() {
    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    do {
        cout << "Pilih Mata Kuliah : " << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
        case '1':
            mataKuliah = &pemrograman;
            break;
        case '2':
            mataKuliah = &jaringan;
            break;
        case '3':
            return 0;
        default:
            cout << "Pilihan tidak valid" << endl;
            continue;
        }

        mataKuliah->inputNilai();
        mataKuliah->cekKelulusan();
    } while (true);

    return 0;
}
