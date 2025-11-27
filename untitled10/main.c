#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- 1. Durum Değişkenleri ---
int saglik = 100;      // 0-100
int enerji = 100;      // 0-100
int yemek_sayisi = 5;  // Başlangıç yemeği
int sığınak_var = 0;   // 0:Yok, 1:Var
int simülasyon_devam = 1; // Komut döngüsünü kontrol eder

// Fonksiyon prototipleri
void envanterGoster();
void avlan();
void sığınakAra();
void dinlen();
void tehlikeSimulasyonu();
void şifreliİlerleme();

int main() {
    // Rastgele sayı üreteci başlangıcı
    srand(time(NULL));

    char komut;

    printf("--- Hayatta Kalma Simülatörü Başlatılıyor ---\n");
    printf("Komutlar: A (Avlan), S (Sığınak), R (Dinlen), E (Envanter), F (Tehlike), P (Şifre), X (Çıkış)\n");

    // İlk durumu göster
    envanterGoster();

    // --- Komut Dinleme Döngüsü (DO-WHILE) ---
    do {
        printf("\n>> Komutunuzu Girin (X ile Çıkış): ");
        // Hata Düzeltme: ' %c' kullanımı, önceki scanf'lerden kalan yeni satır karakterini atlamayı sağlar.
        if (scanf(" %c", &komut) != 1) {
            // Okuma hatası olursa veya dosya sonu gelirse döngüyü kır
            simülasyon_devam = 0;
            break;
        }

        // Komutu büyük harfe çevir
        if (komut >= 'a' && komut <= 'z') {
            komut -= 32;
        }

        // --- Komut Sistemi (SWITCH-CASE) ---
        switch (komut) {
            case 'A':
                avlan();
                break;
            case 'S':
                sığınakAra();
                break;
            case 'R':
                dinlen();
                break;
            case 'E':
                envanterGoster();
                break;
            case 'F':
                tehlikeSimulasyonu();
                break;
            case 'P':
                şifreliİlerleme();
                break;
            case 'X':
                printf("\nSimülasyon Sonlandırılıyor...\n");
                simülasyon_devam = 0;
                break;
            default:
                printf("Bilinmeyen komut. Lütfen geçerli bir komut girin (A, S, R, E, F, P, X).\n");
                break;
        }

        // --- Oyun Bitti Kontrolü ---
        if (saglik <= 0) {
            printf("\n!!! Sağlığınız bitti. HAYATTA KALAMADINIZ. !!!\n");
            simülasyon_devam = 0;
        }

    } while (simülasyon_devam);

    return 0;
}

// --- Komut Fonksiyonları ---

void envanterGoster() {
    printf("\n--- Mevcut Durum ---\n");
    printf("Sağlık: %d/100\n", saglik);
    printf("Enerji: %d/100\n", enerji);
    printf("Yemek Sayısı: %d\n", yemek_sayisi);
    printf("Sığınak Durumu: %s\n", sığınak_var ? "Bulundu (Güvendesiniz)" : "Bulunmadı (Risk Altındasınız)");
    printf("--------------------\n");
}

// Komut A: Avlan
void avlan() {
    // Enerji kontrolü
    if (enerji < 20) {
        printf("Enerjiniz çok düşük! Avlanmak için yeterince gücünüz yok. Dinlenmelisiniz.\n");
        return;
    }

    // --- Aritmetik İşlem ---
    enerji -= 20;

    printf("Avlanmaya çıktınız. Enerjiniz 20 azaldı. Kalan enerji: %d.\n", enerji);

    int sans = rand() % 100;

    // --- Mantıksal Operatörler (&&, ||) ve IF ---
    // Yemek bulma ihtimali enerji ve rastgele şansa bağlı.
    if ((sans >= 50 && enerji >= 30) || sığınak_var) {
        // Başarılı Av
        int kazanilan_yemek = rand() % 3 + 1;
        // Hata Düzeltme: yemek_sayisı yerine yemek_sayisi kullanıldı.
        yemek_sayisi += kazanilan_yemek;
        printf("Başarılı bir av! %d adet yemek buldunuz. Yemek sayınız: %d.\n", kazanilan_yemek, yemek_sayisi);

    } else if (sans < 15 && enerji < 50) {
        // Yaralanma Şansı
        int kaybedilen_saglik = rand() % 10 + 5;
        saglik -= kaybedilen_saglik;
        printf("Av sırasında yaralandınız! %d sağlık kaybettiniz. Yeni sağlık: %d.\n", kaybedilen_saglik, saglik);

    } else {
        // Başarısız Av
        printf("Bu sefer bir şey bulamadınız.\n");
    }
}

// Komut S: Sığınak Ara
void sığınakAra() {
    if (sığınak_var) {
        printf("Zaten bir sığınağınız var.\n");
        return;
    }

    printf("Güvenli bir sığınak arıyorsunuz...\n");

    int sans = rand() % 100;

    // --- IF-ELSE Yapıları ---
    if (sans >= 70) {
        sığınak_var = 1;
        printf("Harika! Sağlam bir sığınak buldunuz. Artık daha güvendesiniz.\n");

    } else if (sans >= 30 && enerji > 50) {
        sığınak_var = 1;
        printf("Yorucu bir arayıştan sonra nihayet bir sığınak buldunuz.\n");

    } else {
        enerji -= 10;
        printf("Sığınak bulamadınız. Enerjiniz 10 düştü. Kalan enerji: %d.\n", enerji);
        if (enerji < 0) enerji = 0;
    }
}

// Komut R: Dinlen
void dinlen() {
    if (yemek_sayisi <= 0) {
        printf("!!! Yeterli yemeğiniz yok. Dinlenmek yerine aç kalıyorsunuz ve biraz sağlık kaybediyorsunuz. !!!\n");
        saglik -= 5;
        return;
    }

    printf("Dinleniyorsunuz. Gücünüzü topluyorsunuz...\n");

    // Dinlenmek için yemek tüketimi ve durum artışı
    yemek_sayisi -= 1;

    // --- Aritmetik İşlemler ---
    enerji += 30;
    saglik += 10;

    // Maksimum sınırları kontrol et
    if (enerji > 100) enerji = 100;
    if (saglik > 100) saglik = 100;

    printf("Dinlendiniz. 1 yemek harcandı. Sağlık: %d, Enerji: %d.\n", saglik, enerji);
}

// Komut F: Tehlike Serisi Simülasyonu
void tehlikeSimulasyonu() {
    printf("!!! Bölgedeki tehlike serisi BAŞLIYOR !!!\n");
    int dalga_sayisi = 3;

    // --- FOR Döngüsü Zorunluluğu ---
    for (int i = 1; i <= dalga_sayisi; i++) {
        printf("--- Dalga %d ---\n", i);
        int sans = rand() % 10;

        if (sığınak_var) {
            printf("Sığınakta güvendesiniz. Bu dalgayı hasarsız atlattınız.\n");
        }
        // --- IF-ELSE Yapısı ---
        else if (sans < 3) {
            // Can kaybı
            int hasar = 10 + rand() % 5;
            saglik -= hasar;
            printf("Bölgeye yakalandınız ve %d sağlık kaybettiniz. Yeni sağlık: %d.\n", hasar, saglik);
        } else if (sans < 7) {
            // Enerji kaybı
            enerji -= 15;
            printf("Tehlikeden kaçmak için enerji harcadınız. Enerji: %d.\n", enerji);
        } else {
            // Kaçış
            printf("Hızlı davrandınız ve tehlikeden kaçmayı başardınız!\n");
        }

        if (saglik <= 0) {
            printf("Sağlığınız bitti. Simülasyon sona erdi.\n");
            simülasyon_devam = 0;
            break;
        }
    }
    printf("Tehlike serisi sona erdi.\n");
}

// Komut P: Şifreli İlerleme
void şifreliİlerleme() {
    char doğru_şifre = 'T';
    char tahmin;
    int deneme_sayisi = 0;

    printf("Önünüzde bir engel var. Engeli aşmak için doğru karakteri girin (İpucu: İlk harf).\n");

    // --- DO-WHILE Döngüsü Zorunluluğu ---
    do {
        printf("Karakter tahmini girin: ");
        // Hata Düzeltme: ' %c' kullanımı, tamponlama sorununu çözer.
        scanf(" %c", &tahmin);
        deneme_sayisi++;

        // Tahmini büyük harfe çevir
        if (tahmin >= 'a' && tahmin <= 'z') {
            tahmin -= 32;
        }

        if (tahmin != doğru_şifre) {
            printf("Yanlış karakter! Tekrar deneyin.\n");
        }

        // 3 denemeden sonra ceza
        if (deneme_sayisi >= 3 && tahmin != doğru_şifre) {
            saglik -= 5;
            printf("Çok denediniz. 5 sağlık kaybettiniz. Yeni sağlık: %d.\n", saglik);
            if (saglik <= 0) {
                printf("Sağlığınız bitti. Simülasyon sona erdi.\n");
                simülasyon_devam = 0;
                return;
            }
        }

    } while (tahmin != doğru_şifre && simülasyon_devam);

    if (simülasyon_devam) {
        printf("\n*** ENGEL AŞILDI! (%d deneme) ***\n", deneme_sayisi);
        printf("Başarıyla ilerlediniz. Enerji yenilendi.\n");
        enerji = 100;
    }
}