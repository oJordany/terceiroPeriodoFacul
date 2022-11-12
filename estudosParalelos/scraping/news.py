import requests
from bs4 import BeautifulSoup
import json


def searchForNewsOnG1(request, pageNumber):
    response = requests.get(f"https://g1.globo.com/busca/?q={request}&page={pageNumber}")

    content = response.content

    sitePage = BeautifulSoup(content, "html.parser")

    return sitePage


def filterInformation(sitePage,newsList=[]):
    newsContainers = sitePage.findAll("div",attrs={"class":"widget--info__text-container"})
    source = []
    for newsContainer in newsContainers:
        try:
            source.append(newsContainer.find("div", attrs={"class": "widget--info__header"}).text)
        except:
            source.append(None)
    links = [newsContainer.a["href"] for newsContainer in newsContainers]
    titles = [newsContainer.find("div", attrs={"class": "widget--info__title"}).text for newsContainer in newsContainers]
    descriptions = [newsContainer.find("p", attrs={"class": "widget--info__description"}).text for newsContainer in newsContainers]
    time = [newsContainer.find("div", attrs={"class": "widget--info__meta"}).text for newsContainer in newsContainers]

    for i in range(0, len(newsContainers)):
        newsList.append({"source":source[i], 
                         "link":f"https:{links[i]}", 
                         "title":titles[i],
                         "description": descriptions[i], 
                         "time":time[i]})
    return newsList


def searchLaucher(searchTerm):
    searchTerm = searchTerm.replace(" ", "+")
    nextPage = True
    pageNumber = 0

    while (nextPage):
        pageNumber += 1
        if (pageNumber == 1):
            newsList = filterInformation(searchForNewsOnG1(searchTerm, pageNumber))
        else:
            newsList = filterInformation(searchForNewsOnG1(searchTerm, pageNumber), newsList)
        print(pageNumber)
        sitePage = searchForNewsOnG1(searchTerm, pageNumber)
        nextPage = sitePage.find("a", attrs={"class": "pagination__load-more"})
    return newsList


searchTerm = "roubo carro forte"
newsList = searchLaucher(searchTerm)
with open("json/scraping.json", "w", encoding="utf8") as f:
    json.dump(newsList, f, ensure_ascii=False, sort_keys=True, indent=4, separators=(',',':'))