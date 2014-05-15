from bs4 import BeautifulSoup
import urllib2
			

#url = raw_input("Enter link:")

#store = urllib2.urlopen(url).read()
#print store
f=open("matchlist.txt", "r")
store=f.read()
f.close()
soup = BeautifulSoup(store)
#print (soup.prettify())
added=[]

matchlist = soup.find_all(class_ = "ciSeriesbrwlink")


for ml in matchlist:
	print ml
	
	cur = ml.get("href")
	
	
		
	print cur
	a = cur.find('match/')
	b = cur.find('.html')
	if a is not -1 and b is not -1 :
		st = a + 6
		en = b
		mid = int(cur[st:en])
		print mid
		f=open("ipl2013matchlist.txt", "a")
		f.write(str(mid)+"\n")
		f.close()