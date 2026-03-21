Import("env")
import os
import subprocess


def _boot_app0_path(build_dir, env):
    local_copy = os.path.join(build_dir, "boot_app0.bin")
    if os.path.exists(local_copy):
        return local_copy

    framework_dir = env.PioPlatform().get_package_dir("framework-arduinoespressif32")
    return os.path.join(framework_dir, "tools", "partitions", "boot_app0.bin")


def after_build(source, target, env):
    build_dir = env.subst("$BUILD_DIR")
    merged = os.path.join(build_dir, "merged-yoradio.bin")
    boot_app0 = _boot_app0_path(build_dir, env)

    esptool_script = None
    esptool_pkg = env.PioPlatform().get_package_dir("tool-esptoolpy")
    if esptool_pkg:
        candidate = os.path.join(esptool_pkg, "esptool.py")
        if os.path.exists(candidate):
            esptool_script = candidate

    cmd = [env.subst("$PYTHONEXE")]
    esptool_mode = "module"
    if esptool_script:
        cmd.append(esptool_script)
        esptool_mode = "platformio-tool"
    else:
        cmd.extend(["-m", "esptool"])

    cmd.extend([
        "--chip", "esp32",
        "merge_bin",
        "-o", merged,
        "0x1000", os.path.join(build_dir, "bootloader.bin"),
        "0x8000", os.path.join(build_dir, "partitions.bin"),
        "0xe000", boot_app0,
        "0x10000", os.path.join(build_dir, "firmware.bin"),
    ])

    print("Merging firmware with esptool mode:", esptool_mode)
    try:
        subprocess.check_call(cmd)
    except subprocess.CalledProcessError as exc:
        raise RuntimeError(
            "Failed to merge firmware binaries. "
            f"esptool mode: {esptool_mode}, command: {' '.join(cmd)}"
        ) from exc
    print("Merged BIN created:", merged)

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", after_build)
