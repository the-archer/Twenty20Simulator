from bs4 import BeautifulSoup
import urllib2
			

url = raw_input("Enter link:")

store = urllib2.urlopen(url).read()

f=open("soupstore.txt", "w")
f.write(store)
f.close()