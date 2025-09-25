static const Block blocks[] = {
    {"",   "amixer get Master | awk -F'[][]' 'END{if($4==\"off\"){print \"MUTE\"}else{print \"VOL \"$2}}'", 1, 10},
    {"CPU ",   "top -bn1 | grep 'Cpu(s)' | awk '{print 100 - $8 \"%\"}'", 2,  0},
    {"TEMP ",  "sensors | awk '/Package id 0:/ {print $4}'",           5,  0},
    {"MEM ",   "free -h --giga | awk '/Mem:/ {print $3 \"/\" $2}'",    5,  0},
    {"IP ",   "ip -4 addr show wlan0 | awk '/inet / {print $2}' | cut -d/ -f1", 10, 0},
    {"",       "date '+%a %b %d, %Y %H:%M'",                           30, 0},
};

static char delim[] = " | ";
static unsigned int delimLen = 5;

