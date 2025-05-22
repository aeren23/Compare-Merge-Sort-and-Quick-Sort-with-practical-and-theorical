import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# CSV dosyasını oku
df = pd.read_csv("results.txt")

# n*log2(n) hesapla
df["nlogn"] = df["n"] * np.log2(df["n"])

# Ortalama c değerlerini hesapla
c_merge_avg = df["merge_c"].mean()
c_quick_avg = df["quick_c"].mean()

print(f"MergeSort Ortalama c: {c_merge_avg}")
print(f"QuickSort Ortalama c: {c_quick_avg}")

# Teorik T(n) değerlerini hesapla
df["merge_T_theoretical"] = c_merge_avg * df["nlogn"]
df["quick_T_theoretical"] = c_quick_avg * df["nlogn"]

# Figure 1: T(n) Deneysel ve Teorik Grafik
plt.figure(figsize=(10, 6))
plt.plot(df["n"], df["merge_Tn"], label="MergeSort Deneysel", marker='o')
plt.plot(df["n"], df["merge_T_theoretical"], label="MergeSort Teorik", linestyle='--', marker='o')
plt.plot(df["n"], df["quick_Tn"], label="QuickSort Deneysel", marker='o')
plt.plot(df["n"], df["quick_T_theoretical"], label="QuickSort Teorik", linestyle='--', marker='o')

plt.xlabel("n")
plt.ylabel("Süre (saniye)")
plt.title("Deneysel ve Teorik Süre Karşılaştırması")
plt.legend()
plt.grid(True)
plt.tight_layout()

# JPEG olarak kaydet
plt.savefig("Tn_grafik.jpeg", dpi=300)

plt.show()

# Figure 2: c katsayıları grafiği ve tablo aynı figure'da
fig, axs = plt.subplots(2, 1, figsize=(10, 10))

# c katsayıları grafiği
axs[0].plot(df["n"], df["merge_c"], label="MergeSort c", marker='o')
axs[0].plot(df["n"], df["quick_c"], label="QuickSort c", marker='o')
axs[0].set_xlabel("n")
axs[0].set_ylabel("c Faktörü")
axs[0].set_title("Farklı Dizi Boyutları için c Katsayıları")
axs[0].legend()
axs[0].grid(True)

# c katsayıları tablosu
table_data = df[["n", "merge_c", "quick_c"]]
axs[1].axis('off')
table = axs[1].table(cellText=table_data.values, colLabels=table_data.columns, loc='center')
table.auto_set_font_size(False)
table.set_fontsize(10)
table.scale(1, 2)
axs[1].set_title("c Katsayıları Tablosu", pad=20)

plt.tight_layout()

# JPEG olarak kaydet
plt.savefig("c_grafik_ve_tablo.jpeg", dpi=300)

plt.show()
