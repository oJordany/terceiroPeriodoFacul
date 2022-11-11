import requests
from bs4 import BeautifulSoup

searchTerm = "roubo de cargas"
searchTerm = searchTerm.replace(" ", "+")
pageNumber = 0
nextPage = True

def searchForNewsOnG1(request, pageNumber):
    response = requests.get(f"https://g1.globo.com/busca/?q={request}&page={pageNumber}")

    content = response.content

    sitePage = BeautifulSoup(content, "html.parser")

    return sitePage

def filterInformation(sitePage, initialObject={}):
    newsContainers = sitePage.findAll("div",attrs={"class":"widget--info__text-container"})
    source = [newsContainer.find("div", attrs={"class": "widget--info__header"}).text for newsContainer in newsContainers]
    links = [newsContainer.a["href"] for newsContainer in newsContainers]
    titles = [newsContainer.find("div", attrs={"class": "widget--info__title"}).text for newsContainer in newsContainers]
    time = [newsContainer.find("div", attrs={"class": "widget--info__meta"}).text for newsContainer in newsContainers]

    for i in range(0, len(newsContainers)):
        initialObject[f"news_{i}"] = {"source":source[i], 
                                      "link":links[i], 
                                      "title":titles[i], 
                                      "time":time[i]}
    return initialObject

while (nextPage):
    pageNumber += 1
    if (pageNumber == 1):
        updatedObject = filterInformation(searchForNewsOnG1(searchTerm, nextPage))
    else:
        updatedObject = filterInformation(searchForNewsOnG1(searchTerm, nextPage), updatedObject)
    print(pageNumber)
    sitePage = searchForNewsOnG1(searchTerm, pageNumber)
    nextPage = sitePage.find("a", attrs={"class": "pagination__load-more"})

# Resultados
# newsList = site.findAll("li", attrs={"class": "widget--info"})
# print(newsList)

# # Título
# title = newsList.find("a", attrs={"class": "feed-post-link"})

# print(title.text) # O conteúdo dentro da tag <a> ==> Título da notícia

