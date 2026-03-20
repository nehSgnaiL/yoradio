Import("env")
import os
import subprocess

def after_build(source, target, env):
    build_dir = env.subst("$BUILD_DIR")
    merged = os.path.join(build_dir, "merged-yoradio.bin")

    cmd = [
        "uv", "run", "python", "-m", "esptool",
        "--chip", "esp32",
        "merge_bin",
        "-o", merged,
        "0x1000", os.path.join(build_dir, "bootloader.bin"),
        "0x8000", os.path.join(build_dir, "partitions.bin"),
        "0x10000", os.path.join(build_dir, "firmware.bin"),
    ]

    subprocess.check_call(cmd)
    print("Merged BIN created:", merged)

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", after_build)