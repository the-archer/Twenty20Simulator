from bs4 import BeautifulSoup
import urllib2

f1=open("ipl2013matchlist.txt", "r")
for line in f1:
	mid=line.rstrip('\n')
	url = "http://www.espncricinfo.com/indian-premier-league-2013/engine/match/" + mid + ".html?view=pvp"
	store = urllib2.urlopen(url).read()
	soup = BeautifulSoup(store)

	plist = soup.find_all(class_ = "engineTable")

	print len(plist)

	for pl in plist:
		b=[0]*7
		runs=0
		balls=0
		bowlers=pl.find_all(class_ = "data1")
		print len(bowlers)
		for bowl in bowlers:
			td=bowl.find_all("td")
			#print len(td)
			
			for x in range(1, 8):
				b[x-1]+=int(td[x].text)
				
			runs+=int(td[10].text)
			balls+=int(td[11].text)
		print b
		print runs
		print balls
		if balls==0:
			continue
		f=open("scoringstats.txt", "a")
		srate=float(runs)/float(balls)*100
		f.write(str(srate))
		for x in range(0, 7):
			f.write(","+str(float(b[x])/float(balls)*100))
		f.write("\n")
		f.close()
	print mid
	print "done"



