from flask import render_template, flash, redirect
from app import app
from .forms import ComputorV1InputForm
import re

@app.route('/')
@app.route('/index')
def index():
    user = {'nickname': 'Student from 42'}
    return render_template('index.html',
                           title='Home',
                           user=user)


@app.route('/computorv1Input', methods=['GET', 'POST'])
def login():
    form = ComputorV1InputForm()
    if form.validate_on_submit():
        flash('Equation entree : %s' %
              form.openid.data)
        computorV1(form.openid.data)
        return redirect('/index')
    return render_template('computorv1Input.html',
                           title='Sign In',
                           form=form,
                           providers=app.config['OPENID_PROVIDERS'])


def multiplicator(num_tab, count, new_num, c_new_num, equal):
    try:
        float(float(num_tab[count])) and float(num_tab[count + 1])
        new_num[c_new_num] = str(float(num_tab[count]) * float(num_tab[count + 1]))
        c_new_num = c_new_num + 1
    except ValueError:
        # Parsed the number in front of everything

        str1 = re.split('[a-zA-Z]', num_tab[count])
        res1 = 1  # value of the int at the beginning of the first expression
        if len(str1[0]) > 0:
            res1 = float(re.split('[a-zA-Z]', num_tab[count])[0])
        str2 = re.split('[a-zA-Z]', num_tab[count + 1])
        res2 = 1  # value of the int at the beginning of the second expression
        if len(str2[0]) > 0:
            res2 = float(re.split('[a-zA-Z]', num_tab[count + 1])[0])

        # Parsing the letter in case it is PRESENT

        deg1 = 1  # Degree value first expression
        deg2 = 1  # Degree value second expression
        if len(str1) > 1 and len(str1[1]) > 0:
            deg1 = int(str1[1][1:])
        if len(str2) > 1 and len(str2[1]) > 0:
            deg2 = int(str2[1][1:])

        x1 = 0  # Is x in the first expression
        x2 = 0  # Is x in the second expression
        charx = 'x'
        regexp = re.compile(r'[a-zA-Z]')
        if regexp.search(num_tab[count]):
            x1 = 1 * deg1
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j
        if regexp.search(num_tab[count + 1]):
            x2 = 1 * deg2
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j

        totalres = res1 * res2 * equal
        x = x1 + x2
        new_num[c_new_num] = str(float(totalres)) + charx + "^" + str(x)
        c_new_num = c_new_num + 1
    return num_tab, count, new_num, c_new_num


def divisor(num_tab, count, new_num, c_new_num, equal):
    try:
        float(float(num_tab[count])) and float(num_tab[count + 1])
        new_num[c_new_num] = str(float(num_tab[count]) / float(num_tab[count + 1]))
        c_new_num = c_new_num + 1
    except ValueError:
        # Parsed the number in front of everything

        str1 = re.split('[a-zA-Z]', num_tab[count])
        res1 = 1  # value of the int at the beginning of the first expression
        if len(str1[0]) > 0:
            res1 = float(re.split('[a-zA-Z]', num_tab[count])[0])
        str2 = re.split('[a-zA-Z]', num_tab[count + 1])
        res2 = 1  # value of the int at the beginning of the second expression
        if len(str2[0]) > 0:
            res2 = float(re.split('[a-zA-Z]', num_tab[count + 1])[0])

        # Parsing the letter in case it is PRESENT

        deg1 = 1  # Degree value first expression
        deg2 = 1  # Degree value second expression
        if len(str1) > 1 and len(str1[1]) > 0:
            deg1 = int(str1[1][1:])
        if len(str2) > 1 and len(str2[1]) > 0:
            deg2 = int(str2[1][1:])

        x1 = 0  # Is x in the first expression
        x2 = 0  # Is x in the second expression
        charx = 'x'
        regexp = re.compile(r'[a-zA-Z]')
        if regexp.search(num_tab[count]):
            x1 = 1 * deg1
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j
        if regexp.search(num_tab[count + 1]):
            x2 = 1 * deg2
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j

        totalres = (res1 / res2) * equal
        x = x1 - x2
        new_num[c_new_num] = str(float(totalres)) + charx + "^" + str(x)
        c_new_num = c_new_num + 1
    return num_tab, count, new_num, c_new_num


def additionator(num_tab, count, new_num, c_new_num, equal):
    try:
        float(float(num_tab[0])) and float(num_tab[1])
        new_num[c_new_num] = str(float(num_tab[0]) + float(num_tab[1]))
        c_new_num = c_new_num + 1
    except ValueError:
        # Parsed the number in front of everything

        str1 = re.split('[a-zA-Z]', num_tab[0])
        res1 = 1  # value of the int at the beginning of the first expression
        if len(str1[0]) > 0:
            res1 = float(re.split('[a-zA-Z]', num_tab[0])[0])
        str2 = re.split('[a-zA-Z]', num_tab[1])
        res2 = 1  # value of the int at the beginning of the second expression
        if len(str2[0]) > 0:
            res2 = float(re.split('[a-zA-Z]', num_tab[1])[0])

        # Parsing the letter in case it is PRESENT

        deg1 = 1  # Degree value first expression
        deg2 = 1  # Degree value second expression
        if len(str1) > 1 and len(str1[1]) > 0:
            deg1 = int(str1[1][1:])
        if len(str2) > 1 and len(str2[1]) > 0:
            deg2 = int(str2[1][1:])

        x1 = 0  # Is x in the first expression
        x2 = 0  # Is x in the second expression
        charx = 'x'
        regexp = re.compile(r'[a-zA-Z]')
        if regexp.search(num_tab[0]):
            x1 = 1 * deg1
            for j in num_tab[0]:
                if j.isalpha():
                    charx = j
        if regexp.search(num_tab[1]):
            x2 = 1 * deg2
            for j in num_tab[0]:
                if j.isalpha():
                    charx = j
        if x1 == x2:
            totalres = (res1 * equal) + (res2 * equal)
            x = x1
            new_num[c_new_num] = str(float(totalres)) + charx + "^" + str(x)
        else:
            if equal == -1 and num_tab[count].find('-') != -1:
                num_tab[count] = str(num_tab[count][1:])
            elif equal == -1:
                num_tab[count] = str('-' + num_tab[count])
            if equal == -1 and num_tab[count + 1].find('-') != -1:
                num_tab[count + 1] = str(num_tab[count + 1][1:])
            elif equal == -1:
                num_tab[count + 1] = str('-' + num_tab[count + 1])
            new_num[c_new_num] = num_tab[count]
            c_new_num = c_new_num + 1
            new_num[c_new_num] = num_tab[count + 1]
    return num_tab, count, new_num, c_new_num


def soustractor(num_tab, count, new_num, c_new_num, equal):
    try:
        float(float(num_tab[count])) and float(num_tab[count + 1])
        new_num[c_new_num] = str(float(num_tab[count]) - float(num_tab[count + 1]))
        c_new_num = c_new_num + 1
    except ValueError:
        # Parsed the number in front of everything

        str1 = re.split('[a-zA-Z]', num_tab[count])
        res1 = 1  # value of the int at the beginning of the first expression
        if len(str1[0]) > 0:
            res1 = float(re.split('[a-zA-Z]', num_tab[count])[0])
        str2 = re.split('[a-zA-Z]', num_tab[count + 1])
        res2 = 1  # value of the int at the beginning of the second expression
        if len(str2[0]) > 0:
            res2 = float(re.split('[a-zA-Z]', num_tab[count + 1])[0])

        # Parsing the letter in case it is PRESENT

        deg1 = 1  # Degree value first expression
        deg2 = 1  # Degree value second expression
        if len(str1) > 1 and len(str1[1]) > 0:
            deg1 = int(str1[1][1:])
        if len(str2) > 1 and len(str2[1]) > 0:
            deg2 = int(str2[1][1:])

        x1 = 0  # Is x in the first expression
        x2 = 0  # Is x in the second expression
        charx = 'x'
        regexp = re.compile(r'[a-zA-Z]')
        if regexp.search(num_tab[count]):
            x1 = 1 * deg1
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j
        if regexp.search(num_tab[count + 1]):
            x2 = 1 * deg2
            for j in num_tab[count]:
                if j.isalpha():
                    charx = j
        if x1 == x2:
            if equal == -1:
                totalres = res2 - res1
            x = x1
            new_num[c_new_num] = str(float(totalres)) + charx + "^" + str(x)
        else:
            if equal == -1 and num_tab[count].find('-') != -1:
                num_tab[count] = str(num_tab[count][1:])
                num_tab[count + 1] = str(num_tab[count + 1][1:])
            elif equal == -1:
                num_tab[count] = str('-' + num_tab[count])
                num_tab[count + 1] = str('-' + num_tab[count + 1])
            new_num[c_new_num] = num_tab[count + 1]
            c_new_num = c_new_num + 1
    return num_tab, count, new_num, c_new_num


def computorV1(equation):

    # Parsing the parameter sent

    parsed = equation.split()
    size_num = 0  # Num Array Size
    isvar = re.compile(r'[a-zA-Z]')

    # Initialise size_num value

    for x in parsed:
        try:
            float(x)
            size_num = size_num + 1
        except ValueError:
            if x.find('^') != -1 or isvar.search(x):
                size_num = size_num + 1
            else:
                size_num = size_num

    ope_tab = ["" for x in range(len(parsed) - size_num)]
    num_tab = ["" for x in range(size_num)]
    c_num_tab = 0
    c_ope_tab = 0

    for i in parsed:

        try:
            float(i)
            num_tab[c_num_tab] = i
            c_num_tab = c_num_tab + 1
        except ValueError:
            if i.find('^') != -1 or isvar.search(i):
                num_tab[c_num_tab] = i
                c_num_tab = c_num_tab + 1
            else:
                ope_tab[c_ope_tab] = i
                c_ope_tab = c_ope_tab + 1

    # X parsing // Simplification

    new_num = ["" for x in range(size_num)]
    c_new_num = 0
    count = 0
    equal = 1
    for i in ope_tab:

        #  Mult

        if i.find("=") != -1:
            equal = -1
            ope_tab[count] = "0"

        if i.find("*") != -1:
            [num_tab, count, new_num, c_new_num] = multiplicator(num_tab, count, new_num, c_new_num, equal)
            ope_tab[count] = "0"
            num_tab[count] = ""
            num_tab[count + 1] = new_num[c_new_num - 1]

        #  Div

        if i.find("/") != -1:
            [num_tab, count, new_num, c_new_num] = divisor(num_tab, count, new_num, c_new_num, equal)
            ope_tab[count] = "0"
            num_tab[count] = ""
            num_tab[count + 1] = new_num[c_new_num - 1]

        count = count + 1
    count = 0

    cpy = ["0" for x in range(size_num)]
    c_cpy = 0
    for x in num_tab:
        if len(x) >= 1:
            cpy[c_cpy] = x
            c_cpy = c_cpy + 1
    num_tab = cpy

    c_cpy = 0
    cpy2 = ["" for x in range(len(parsed) - size_num)]
    for x in ope_tab:
        if x != "0":
            cpy2[c_cpy] = x
            c_cpy = c_cpy + 1
    ope_tab = cpy2
    new_num = ["" for x in range(size_num)]
    c_new_num = 0
    while ope_tab[0] != "0" and len(ope_tab[0]) > 0:

        if ope_tab[0].find("=") != -1:
            equal = -1
            ope_tab[count] = "0"

        if ope_tab[0].find("+") != -1:
            dup = c_new_num
            [num_tab, count, new_num, c_new_num] = additionator(num_tab, count, new_num, c_new_num, equal)
            if dup == c_new_num:
                num_tab[count + 1] = ""
                c_new_num = c_new_num + 1
            num_tab[count] = ""
            ope_tab[count] = "0"

        if ope_tab[0].find("-") != -1:
            dup2 = c_new_num
            [num_tab, count, new_num, c_new_num] = soustractor(num_tab, count, new_num, c_new_num, equal)
            ope_tab[count] = "0"
            if dup2 == c_new_num:
                num_tab[count + 1] = ""
                c_new_num = c_new_num + 1
            num_tab[count] = ""
            ope_tab[count] = "0"

        cpy = ["0" for x in range(size_num)]
        c_cpy = 0
        for x in num_tab:
            if len(x) >= 1:
                cpy[c_cpy] = x
                c_cpy = c_cpy + 1
        num_tab = cpy

        c_cpy = 0
        cpy2 = ["0" for x in range(len(parsed) - size_num)]
        for x in ope_tab:
            if x != "0":
                cpy2[c_cpy] = x
                c_cpy = c_cpy + 1
        ope_tab = cpy2

    #  Prepare for the result
    c_new_num = 0
    result = ""
    for i in new_num:
        if len(result) > 0 and len(new_num[c_new_num]) > 0:
            result = str(result + " + " + new_num[c_new_num])
        elif len(result) == 0 and len(new_num[c_new_num]) > 0:
            result = str(new_num[c_new_num])
        c_new_num = c_new_num + 1

    flash('Resultat = %s' % result)
