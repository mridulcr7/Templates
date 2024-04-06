from urllib import response
from django.shortcuts import render

def cat_func(request):
    return render(request,"cat.html")
# Create your views here.
