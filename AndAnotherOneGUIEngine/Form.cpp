#include "Form.h"

void Form::setPosition(float x, float y)
{

}

void Form::setSize(float left, float top)
{
}

void Form::onEvent(Event e, std::map<std::string, std::function<void(Gui * gui)>> commands, bool& isWriting, Gui** targetTextInput)
{
	for (auto g : gui)
	{
		Form* form = dynamic_cast<Form*>(g);
		if (form != NULL)
		{
			form->onEvent(e,commands,isWriting,targetTextInput);
		}
	}

	if (e.type == Event::MouseButtonPressed)
	{
		if (e.mouseButton.button == Mouse::Left)
		{
			FloatRect mouseRect(e.mouseButton.x, e.mouseButton.y, 1, 1);

			if (isWriting && !mouseRect.intersects((*targetTextInput)->getRect()))
			{
				isWriting = 0;
				dynamic_cast<WritableGui*>((*targetTextInput))->writed = 0;
				targetTextInput = NULL;
			}

			for (auto g : gui)
				if (g->isVisible && g->getRect().intersects(mouseRect))
				{
					ClicableGui* clicable = dynamic_cast<ClicableGui*>(g);
					if (clicable != NULL)
					{
						commands[clicable->onClick](g);
						clicable->clicked = 1;
					}

					WritableGui* writable = dynamic_cast<WritableGui*>(g);
					if (writable != NULL)
					{
						if (!isWriting)
						{
							isWriting = 1;
							(*targetTextInput) = g;
						}

						else if ((*targetTextInput)->getId() != g->getId())
						{
							dynamic_cast<WritableGui*>((*targetTextInput))->writed = 0;
							(*targetTextInput) = g;
						}
						writable->writed = 1;
					}
				}
		}
	}
	else if (e.type == sf::Event::MouseMoved)
	{
		FloatRect mouseRect(e.mouseMove.x, e.mouseMove.y, 1, 1);

		for (auto g : gui)
			if (g->isVisible)
			{
				CoverableGui* coverable = dynamic_cast<CoverableGui*>(g);

				if (coverable != NULL)
				{
					if (g->getRect().intersects(mouseRect) && !coverable->covered)
					{
						coverable->covered = 1;
						commands[coverable->onCover](g);
					}
					else if (!g->getRect().intersects(mouseRect) && coverable->covered)
					{
						coverable->covered = 0;
						commands[coverable->onCover](g);
					}
				}
			}
	}
	else if (e.type == sf::Event::TextEntered)
	{

		if (isWriting && ((e.text.unicode >= 48 && e.text.unicode <= 57) || (e.text.unicode >= 65 && e.text.unicode <= 90) || (e.text.unicode >= 97 && e.text.unicode <= 122) || e.text.unicode == 32))
		{
			if (static_cast<char>(e.text.unicode) != NULL)
			{
				dynamic_cast<WritableGui*>((*targetTextInput))->tryInput(static_cast<char>(e.text.unicode));
			}
		}
	}
	else if (e.type == sf::Event::KeyPressed)
	{
		if (isWriting)
			if (e.key.code == Keyboard::BackSpace)
				dynamic_cast<WritableGui*>((*targetTextInput))->tryDelite();
			else if (e.key.code == Keyboard::Enter)
			{
				isWriting = 0;
				dynamic_cast<WritableGui*>((*targetTextInput))->writed = 0;
				(*targetTextInput) = NULL;
			}
	}
	else if (e.type == Event::MouseButtonReleased)
	{
		if (e.mouseButton.button == Mouse::Left)
		{
			for (auto g : gui)
				if (g->isVisible)
				{
					ClicableGui* clicable = dynamic_cast<ClicableGui*>(g);
					if (clicable != NULL)
					{
						clicable->clicked = 0;
						commands[clicable->onClick](g);
					}
				}
		}
	}
}

void Form::draw(RenderWindow& w)
{
	for (auto g : gui)
	{
		if (g->isVisible)
		{
			Form* form = dynamic_cast<Form*>(g);
			if (form != NULL)
				form->draw(w);

			DrawableGui* drawing = dynamic_cast<DrawableGui*>(g);
			if (drawing != NULL)
				drawing->draw(w);
		}
	}
}

void Form::update(float gameTime, Vector2i mouse)
{
	for (auto g : gui)
		if (g->isVisible)
		{
			Form* form = dynamic_cast<Form*>(g);
			if (form != NULL)
				form->update(gameTime, mouse);

			DrawableGui* drawing = dynamic_cast<DrawableGui*>(g);
			if (drawing != NULL)
				drawing->update(gameTime, mouse);
		}
}

Form::Form(std::string id, FloatRect rect, bool visible) :
	Gui(id,rect,visible) {}
