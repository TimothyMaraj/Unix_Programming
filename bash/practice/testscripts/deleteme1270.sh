"""
TODO: FIX INNER CAT
"""


#!/bin/bash
rand=$RANDOM


touch deleteme$rand.sh


cat 
" #!/bin/bash \n rand=\$RANDOM \n touch deleteme\${rand}.sh \n chmod +x * \n

cat 
\" \" #!/bin/bash rand=\$RANDOM touch deleteme\${rand}.sh chmod +x * echo \"The name of the file is: \$0 and it is going to be self-deleted.\" rm -f \"\$0\" \" >> deleteme$rand.sh


echo \"The name of the file is: \$0 and it is going to be self-deleted.\"
rm -f \"\$0\"
" > deleteme$rand.sh

chmod +x *
echo "The name of the file is: \$0 and it is going to be self-deleted."
rm -f "$0"
