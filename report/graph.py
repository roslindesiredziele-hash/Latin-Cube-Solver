import pandas as pd
import matplotlib.pyplot as plt

# ==================================================
# Load Data
# ==================================================

df = pd.read_csv("data/benchmark.csv")

plt.style.use("default")

# ==================================================
# Graph 1
# Runtime vs Cube Size (Log Scale)
# ==================================================

plt.figure(figsize=(10, 6))

for ratio in sorted(df["MaskRatio"].unique()):
    subset = df[df["MaskRatio"] == ratio]

    plt.plot(
        subset["CubeSize"],
        subset["RuntimeMs"],
        marker="o",
        linewidth=2,
        label=f"Mask {ratio:.1f}"
    )

plt.title("Runtime vs Cube Size")
plt.xlabel("Cube Size")
plt.ylabel("Runtime (ms)")

plt.yscale("log")

plt.grid(True, which="both", alpha=0.3)
plt.legend(title="Mask Ratio")

plt.tight_layout()

plt.savefig(
    "report/runtime_vs_size_log.png",
    dpi=300
)

# ==================================================
# Graph 2
# Recursive Calls vs Cube Size
# ==================================================

plt.figure(figsize=(10, 6))

for ratio in sorted(df["MaskRatio"].unique()):
    subset = df[df["MaskRatio"] == ratio]

    plt.plot(
        subset["CubeSize"],
        subset["RecursiveCalls"],
        marker="o",
        linewidth=2,
        label=f"Mask {ratio:.1f}"
    )

plt.title("Recursive Calls vs Cube Size")
plt.xlabel("Cube Size")
plt.ylabel("Recursive Calls")

plt.yscale("log")

plt.grid(True, which="both", alpha=0.3)
plt.legend(title="Mask Ratio")

plt.tight_layout()

plt.savefig(
    "report/recursive_calls_vs_size.png",
    dpi=300
)

# ==================================================
# Graph 4
# Runtime vs Mask Ratio (Sizes 9 and 10)
# Log Scale
# ==================================================

plt.figure(figsize=(10, 6))

for size in [9, 10]:
    subset = df[df["CubeSize"] == size]

    plt.plot(
        subset["MaskRatio"],
        subset["RuntimeMs"],
        marker="o",
        linewidth=3,
        label=f"Size {size}"
    )

plt.title(
    "Runtime vs Mask Ratio (Log Scale) (Sizes 9 and 10)"
)

plt.xlabel("Mask Ratio")
plt.ylabel("Runtime (ms)")

plt.yscale("log")

plt.grid(True, which="both", alpha=0.3)
plt.legend(title="Cube Size")

plt.tight_layout()

plt.savefig(
    "report/runtime_pair_9_10_log.png",
    dpi=300
)

# ==================================================
# Graph 5
# Recursive Calls vs Cube Size (60% Masking)
# ==================================================

plt.figure(figsize=(10, 6))

hard = df[df["MaskRatio"] == 0.60]

plt.plot(
    hard["CubeSize"],
    hard["RecursiveCalls"],
    marker="o",
    linewidth=3,
    color="darkgreen"
)

plt.title(
    "Recursive Calls vs Cube Size (60% Masking)"
)

plt.xlabel("Cube Size")
plt.ylabel("Recursive Calls")

plt.yscale("log")

plt.grid(True, which="both", alpha=0.3)

for size, calls in zip(
    hard["CubeSize"],
    hard["RecursiveCalls"]
):
    plt.annotate(
        str(calls),
        (size, calls),
        textcoords="offset points",
        xytext=(0, 8),
        ha="center"
    )

plt.tight_layout()

plt.savefig(
    "report/hard_recursive_calls.png",
    dpi=300
)

print("graphs save in report/    :)")

plt.show()