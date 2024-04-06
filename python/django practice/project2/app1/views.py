from django.shortcuts import render
from django.http import HttpResponse

def app1_func1(request):
    return HttpResponse('you are at app1')
# Create your views here.
