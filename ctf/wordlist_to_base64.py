#!/usr/bin/env python3
# Script to create a list of base64 encoded strings
# from a wordlist.
# Useful for cracking passwords that are stored as
# hashes of base64 encodings of the original password.
# 
# Example:
# 
# Hash to be cracked: 303ed2b249552d6e9758ca4b6f68da7c
# 
# hashcat -m 0 -a 0 hash.txt rockyou64.txt
#   -> 303ed2b249552d6e9758ca4b6f68da7c:cm9ja3lvdQ==
#
# echo -n cm9ja3lvdQ== | base64 -d -
#   rockyou


import base64
file_in = open("rockyou.txt","r", encoding="latin1")
file_out = open("rockyou64.txt","w")
for line in file_in:
   file_out.write(base64.b64encode(bytes(str.strip(line), 'utf-8')).decode("utf-8") + "\n")
