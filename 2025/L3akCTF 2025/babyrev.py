remap = "qwertyuiopasdfghjklzxcvbnm_"
alphabet = "abcdefghijklmnopqrstuwvxyz_"
encrypted_flag = "ngx_qkt_fgz_ugffq_uxtll_dt"
decrypted_flag = ""

for char in encrypted_flag:
    decrypted_flag += alphabet[remap.index(char)]

print("L3AK{"+decrypted_flag+"}")
