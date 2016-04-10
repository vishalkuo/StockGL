import requests
base_url = 'http://ichart.finance.yahoo.com/table.csv'
payload = {
	's': 'VTI',
	'd': '0',
	'e': '28',
	'f': '2010',
	'g': 'd',
	'a': '3',
	'b': '12',
	'c': '2008',
	'ignore': '.csv'
}

payload_one={
	's': 'VTI'
}

r = requests.get(base_url, params=payload)

print(r.text)