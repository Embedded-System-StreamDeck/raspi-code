#!/bin/bash
# ARM64 ve eski sistemler için kurulum scripti
set -e
BUILD_DIR="$(dirname "$0")/build"
if [ ! -d "$BUILD_DIR" ]; then
  echo "Önce build.sh ile derleyin."
  exit 1
fi
sudo cp "$BUILD_DIR/ClientSideRaspi" /usr/local/bin/
echo "Kurulum tamamlandı."
