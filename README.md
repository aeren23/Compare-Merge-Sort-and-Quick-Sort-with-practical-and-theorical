# CENG 204 - QuickSort ve MergeSort Çalışma Süresi Analizi

Bu projede, **QuickSort** ve **MergeSort** algoritmalarının farklı boyutlardaki diziler üzerinde **deneysel çalışma süreleri** ve **teorik karmaşıklık değerleri** karşılaştırılmıştır.

## 📑 İçerik

* `main.c` : QuickSort ve MergeSort algoritmalarının C dilindeki uygulamaları, süre ölçme ve sonuç kaydetme.
* `results.txt` : 50 çalıştırmanın ortalama süre sonuçları ve c katsayıları.
* `grafikler/` :

  * `Tn_grafik.jpeg` : Deneysel ve teorik süre karşılaştırma grafiği
  * `c_grafik_ve_tablo.jpeg` : c katsayıları grafiği ve tablo
* `grafik_analiz.py` : Python ile grafik çizme ve analiz scripti
* `rapor.docx` : Ödev rapor dosyası (isteğe bağlı)

## 📊 Proje Özeti

* Her algoritma için **1000, 5000, 10000, 50000, 100000, 200000** elemanlı dizilerde 50’şer çalıştırma yapılmıştır.
* Çalışma süreleri ölçülerek `c` katsayıları hesaplanmıştır.
* Deneysel ve teorik değerler karşılaştırılarak grafikler oluşturulmuştur.

## 📎 Çalıştırma

### C Kodları için:

```bash
gcc main.c -o sorting.exe
./sorting.exe
```

### Python Grafik Scripti için:

```bash
pip install pandas matplotlib numpy
python grafik_analiz.py
```

## 📷 Örnek Çıktılar

**Deneysel ve Teorik T(n) Grafiği**
![Deneysel ve Teorik Tn](grafikler/Tn_grafik.jpeg)

**c Katsayıları ve Tablosu**
![c Katsayıları](grafikler/c_grafik_ve_tablo.jpeg)


## 📝 Not

Bu proje **CENG 204 Algoritmalar Dersi** ödevi kapsamında hazırlanmıştır.
