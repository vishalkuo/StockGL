import requests
import ConfigParser
import os
from os import path
from os.path import join


current_path = path.realpath(path.join(os.getcwd(), path.dirname(__file__)))
resources_path = path.join(current_path, os.pardir, 'StockGL', 'Resources')

base_url = 'http://ichart.finance.yahoo.com/table.csv'
config = ConfigParser.SafeConfigParser()
global_config_header = 'global'
config.read('config.ini')
tickers = config.get(global_config_header, 'tickers')
month_to = config.get(global_config_header, 'month_to')
day_to = config.get(global_config_header, 'day_to')
year_to = config.get(global_config_header, 'year_to')
month_from = config.get(global_config_header, 'month_from')
day_from = config.get(global_config_header, 'day_from')
year_from = config.get(global_config_header, 'year_from')
for ticker in tickers.split(','):
	payload = {
	's': ticker,
	'd': month_to,
	'e': day_to,
	'f': year_to,
	'g': 'd',
	'a': month_from,
	'b': day_from,
	'c': year_from,
	'ignore': '.csv'
	}	
	r = requests.get(base_url, params=payload)
	with open('{0}/{1}.csv'.format(resources_path, ticker), 'w') as f:
		f.write(r.text)
