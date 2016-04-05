#########################################################################
# File Name: rebuild.sh
# Author: shift
# mail: open_shift@163.com
# Created Time: 2016年03月27日 星期日 22时17分38秒
#########################################################################
#!/bin/bash
make distclean
make DIY2440_config
make
