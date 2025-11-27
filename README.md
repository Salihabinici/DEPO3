# DEPO3
#  survival-simulator-c
## ⚔️ Karakter Tabanlı Hayatta Kalma Simülatörü (C İle Metin Tabanlı Oyun)
Bu proje, **Algoritma ve Programlama Dersi Ödev-2** kapsamında geliştirilmiş, C dilinin temel yapılarını (döngüler, koşul yapıları, operatörler) kullanarak oluşturulmuş **metin tabanlı** bir hayatta kalma simülatörüdüdür.
Simülatör, oyuncunun komutlarına göre karakterin **Sağlık, Enerji ve Envanter** durumlarını dinamik olarak yönetir ve zorunlu C yapılarını uygulamalı olarak gösterir.
---
## ✨ Zorunlu C Yapılarının Uygulanması
Proje, aşağıdaki temel C yapılarını kullanmak üzere tasarlanmıştır:
### 1. Komut Yönetimi (SWITCH-CASE)
Oyuncudan alınan tek karakterli komutlar, ana döngü içerisinde yer alan **SWITCH-CASE** yapısı ile anında ve verimli bir şekilde yönlendirilir. Bu, komut akışını düzenli ve okunabilir tutar.
### 2. Döngü Mekanizmaları
| Yapı | Komut | Kullanım Amacı |
| :---: | :---: | :--- |
| **DO-WHILE** | `P` (Şifreli İlerleme) | Oyuncu doğru karakteri girene kadar denemeye zorlayan **doğrulama döngüsü** oluşturur. |
| **FOR** | `F` (Tehlike Serisi) | Belirli sayıda tekrar eden (örn. 3 dalga) bir **tehlike simülasyonu**nu yürütmek için kullanılır. |
### 3. Kontrol ve Karar Yapıları (IF-ELSE)
* **Sığınak Arama (`S`):** Sığınak bulma şansı, farklı koşullara (rastgele şans, mevcut enerji) göre **IF-ELSE IF-ELSE** yapısıyla değerlendirilir.
* **Durum Kontrolü:** Sağlık veya enerjinin maksimum (100) veya minimum (0) değerlerinin kontrol edilmesinde ve komutların (örn. `R` - Dinlen) yemek durumuna göre farklı sonuçlar üretmesinde kullanılır.
### 4. Operatörler (Aritmetik & Mantıksal)
* **Aritmetik Operatörler:** Sağlık (`+`, `-`) ve Enerji (`+`, `-`) gibi durum değişkenlerinin komutlara bağlı olarak sürekli güncellenmesi (**Dinlenme** veya **Avlanma**) için kullanılır.
* **Mantıksal Operatörler (`&&`, `||`):** **Avlanma (`A`)** komutunda, oyuncunun hem yeterli enerjiye sahip olması **VE** rastgele şansın yüksek olması gibi birden fazla koşulun aynı anda sağlanıp sağlanmadığını kontrol etmek için kullanılır.
---
## 🎮 Komutlar ve İşlevleri
| Komut | Açıklama |
| :---: | :--- |
| **A** | **Avlan**: Enerji harcar, yemek kazanma veya yaralanma ihtimalini mantıksal operatörlerle hesaplar. |
| **S** | **Sığınak Ara**: Başarı ihtimali IF-ELSE yapılarıyla değerlendirilir. |
| **R** | **Dinlen**: 1 yemek harcar. Sağlık ve enerji artışı aritmetik operatörlerle yönetilir. |
| **E** | **Envanteri Görüntüle**: Mevcut Sağlık, Enerji, Yemek ve Sığınak durumunu gösterir. |
| **F** | **Tehlike Serisi**: FOR döngüsü ile 3 dalgalı tehlikeyi simüle eder, hasar veya kaçış sonuçları üretir. |
| **P** | **Şifreli İlerleme**: DO-WHILE döngüsü ile doğru karakteri girene kadar zorlu bir geçiş mekanizması mekanizması simüle eder. |
| **X** | **Çıkış**: Simülasyonu sonlandırır. |

---
## 🛠️ Kurulum ve Çalıştırma
Bu proje standart bir C derleyicisi (GCC önerilir) ile derlenip çalıştırılabilir.
### Gereksinimler
* C Derleyicisi (GCC, Clang, vb.)
### Derleme
```bash
gcc survival_simulator.c -o survival
