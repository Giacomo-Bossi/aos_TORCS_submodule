cd "$TORCS_BASE" || { echo "Impossible to move to $TORCS_BASE. Exiting."; exit 1; }
./configure || { echo "Configure failed. Exiting."; exit 1; }
make || { echo "Make failed. Exiting."; exit 1; }
make install || { echo "Make install failed. Exiting."; exit 1; }
make datainstall || { echo "Make datainstall failed. Exiting."; exit 1; }

echo "configuration and compilation successful" 