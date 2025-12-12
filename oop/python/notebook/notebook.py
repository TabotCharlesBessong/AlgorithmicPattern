from note import Note


class Notebook:
  '''Represents a collection of notes that can be tagged, modified, and searched.'''
  def __init__(self):
    '''Initialize a notebook with an empty list of notes.'''
    self.notes = []
    
  def new_note(self, memo, tags=''):
    '''Create a new note and add it to the notebook.'''
    self.notes.append(Note(memo, tags))
    
  def _find_note(self, note_id):
    '''Locate the note with the given id.'''
    for note in self.notes:
      if str(note.id) == str(note_id):
        return note
    return None
    
  def modify_memo(self, note_id, memo):
    '''Find the note with the given id and change its memo to the given value.'''
    for note in self.notes:
      if note.id == note_id:
        note.memo = memo
        break
        
  def modify_tags(self, note_id, tags):
    '''Find the note with the given id and change its tags to the given value.'''
    for note in self.notes:
      if note.id == note_id:
        note.tags = tags
        break
        
  def search(self, filter):
    '''Find all notes that match the given filter string.'''
    return [note for note in self.notes if note.match(filter)]
    
  def _find_note(self, note_id):
    '''Locate the note with the given id.'''
    for note in self.notes:
      if str(note.id) == str(note_id):
        return note
    return None