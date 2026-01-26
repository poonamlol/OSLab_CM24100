
#!/bin/bash

echo "===== FILE HANDLING MENU ====="
echo "1. Create File"
echo "2. Write Content"
echo "3. Append Content"
echo "4. Delete File"
echo "5. Exit"

read -p "Enter choice: " ch

case $ch in
  1)
     read -p "Enter filename: " fname
     touch $fname
     echo "File created successfully"
     ;;
  2)
     read -p "Enter filename: " fname
     echo "Enter content (Press Ctrl+D when done):"
     cat > $fname
     ;;
  3)
     read -p "Enter filename: " fname
     echo "Enter content to append (Press Ctrl+D when done):"
     cat >> $fname
     ;;
  4)
     read -p "Enter filename: " fname
     rm $fname
     echo "File deleted successfully"
     ;;
  5)
     exit ;;
  *)
     echo "Invalid choice"
     ;;
esac
