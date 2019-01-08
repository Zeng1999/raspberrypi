#!/usr/bin/expect
set timeout 30

set from [lindex $argv 0]
set dest [lindex $argv 1]

set pass "this is raspi password"

spawn scp $from $dest

expect "assword:"
send "$pass\r"
expect eof

exit
